#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void crear();
void continuar();
void cargar();
void listar();
void consultar();
void modificar();
void eliminar();

/*
Miembros del equipo:
    - Rodriguez Blanco Julio Joshua
    - Luna Martinez Escobar Guillermo
    - Barcenas Gonzalez Sebastian Amadeus
*/

typedef struct{
    int codigo;
    char descripcion[40];
    float precio;
} tproduct;

/*
Funcion que permite crear un archivo de tipo binario
Return void
Parameters NONE
*/
void crear(){
    FILE *arch;
    arch = fopen("productos.dat", "wb");
    if(arch==NULL){
        exit(1);
    }
    fclose(arch);
    continuar();
}

/*
Funcion que me permite regresar al proceso del menu
Return void
Parameters NONE
*/
void continuar(){
    printf("Presiona una tecla para continuar:\n\n");
    // getch();
}

/*
Funcion que carga al archivo binario una estructura de producto
Return void
Parameters NONE
*/
void cargar(){
    FILE *arch;
    arch=fopen("productos.dat", "ab");
    if(arch == NULL){
        exit(1);
    }
    tproduct producto; 

    printf("Ingrese el codigo del producto: ");
    scanf("%d", &producto.codigo);
    fflush(stdin);

    printf("Ingrese el nombre del producto: ");
    // scanf("%s", &producto.descripcion);
    // gets es lo mismo que scanf pero mas optimizado
    scanf("%s",producto.descripcion); // <- Esto es para evitar basura dentro del string que nos da el scanf
    fflush(stdin);

    printf("Ingrese el precio del producto: ");
    scanf("%f", &producto.precio);
    fflush(stdin);

    fwrite(&producto, sizeof(tproduct), 1, arch);
    fclose(arch);
    continuar();
}

/*
Funcion que lista los productos de un archivo binario
Return void
Parameters NONE
*/
void listar(){
    FILE *arch;
    arch=fopen("productos.dat", "rb");
    if(arch==NULL){
        exit(1);
    }
    tproduct producto;

    fread(&producto, sizeof(tproduct), 1, arch);
    while(!feof(arch)){
        printf("%d %s %0.2f\n", producto.codigo, producto.descripcion, producto.precio);
        fread(&producto, sizeof(tproduct), 1, arch);
    }
    fclose(arch);
    continuar();
}


/*
Funcion que busca por codigo un producto desde un archivo
Return void
Parameters NONE
*/
void consultar(){
    FILE *arch;
    int cod;
    tproduct producto;
    bool existe = false; // Banderas

    arch=fopen("productos.dat", "rb");
    if(arch==NULL){
        exit(1);
    }
    printf("Ingresa el codigo del producto a consultar: ");
    scanf("%d", &cod);

    fread(&producto, sizeof(tproduct), 1, arch);
    while(!feof(arch)){
        if(cod==producto.codigo){
            printf("%d %s %0.2f\n", producto.codigo, producto.descripcion, producto.precio);
            existe = true;
            break;
        }
        fread(&producto, sizeof(tproduct), 1, arch);
    }
    if(!existe){
        printf("No existe el producto con dicho codigo");
    }

    fclose(arch);
    continuar();
}

/*
Funcion que me permite modificar el precio de un registro apartir de buscar un codigo
Return void
Parameters NONE
*/
void modificar(){
    FILE *arch;
    int cod;
    tproduct producto;
    bool existe;

    arch=fopen("productos.dat", "r+b");
    if(arch==NULL){
        exit(1);
    }
    printf("Ingresa el codigo de producto a modificar: ");
    scanf("%d", &cod);

    fread(&producto, sizeof(tproduct), 1, arch);
    while(!feof(arch)){
        if(cod==producto.codigo){
            printf("%d %s %0.2f\n", producto.codigo, producto.descripcion, producto.precio);

            printf("Ingresa el nuevo precio: ");
            scanf("%f", &producto.precio);

            int posicion = ftell(arch) - sizeof(tproduct); // Obtiene la posicion del puntero
            fseek(arch, posicion, SEEK_SET);
            fwrite(&producto, sizeof(tproduct), 1, arch);
            printf("Se modifico el precio de dicho producto\n");

            existe=true;
            break;
        }
        fread(&producto, sizeof(tproduct), 1, arch);
    }
    if(!existe){
        printf("No existe el producto con dicho codigo\n");
    }
    fclose(arch);
    continuar();
}

/*
Funcion que elimina un producto de "productos.dat"
Return void
Parameters NONE
*/
void eliminar() {
    FILE *arch;
    FILE *temp;
    int cod;
    tproduct producto;
    bool existe = false;

    arch = fopen("productos.dat", "rb");
    if (arch == NULL) {
        perror("Error al abrir el archivo");
        exit(1);
    }

    temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        perror("Error al abrir el archivo temporal");
        fclose(arch);
        exit(1);
    }

    printf("Ingresa el codigo del producto que deseas eliminar: ");
    scanf("%d", &cod);

    while (fread(&producto, sizeof(tproduct), 1, arch) == 1) {
        if (cod == producto.codigo) {
            existe = true;
        } else {
            fwrite(&producto, sizeof(tproduct), 1, temp);
        }
    }

    fclose(arch);
    fclose(temp);

    if (!existe) {
        remove("temp.dat"); 
        printf("No existe el producto con dicho codigo\n");
    } else {
        remove("productos.dat"); 
        rename("temp.dat", "productos.dat"); 
        printf("Producto eliminado con éxito\n");
    }
    continuar();
}

int main(){
    int opcion;
    do{
        printf("1 - Crear un archivo binario llamado \"productos.dat\"\n");
        printf("2 - Cargar los registros de tipo producto\n");
        printf("3 - Listado completo de productos\n");
        printf("4 - Consulta de un producto por su codigo\n");
        printf("5 - Modificacion del precio de un producto\n");
        printf("6 - Eliminar un elemento de la lista\n");
        printf("7 - Finalizar\n\n");

        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                crear();
                break;
            case 2:
                cargar();
                break;
            case 3:
                listar();
                break;
            case 4:
                consultar();
                break;
            case 5:
                modificar();
                break;
            case 6:
                eliminar();
            default:
                break;
        }
    } while(opcion != 7);
}