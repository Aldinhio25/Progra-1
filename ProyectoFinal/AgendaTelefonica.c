#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    char nombre[40];
    int numero;
} tcontact;

void create();
void load();
void list();
void serch();
void change();
void delete();

void create() {
    FILE *arch;
    arch = fopen("agenda.dat", "ab");
    if (arch == NULL) {
        exit(1);
    }
    fclose(arch);
}

void load() {
    FILE *arch;
    arch = fopen("agenda.dat", "ab");
    if (arch == NULL) {
        exit(1);
    }
    tcontact contacto;

    printf("Ingrese el nombre del contacto: ");
    scanf("%s", contacto.nombre);

    printf("Ingrese el numero telefonico: ");
    scanf("%d", &contacto.numero);

    fwrite(&contacto, sizeof(tcontact), 1, arch);
    fclose(arch);
}

void list() {
    FILE *arch;
    arch = fopen("agenda.dat", "rb");
    if (arch == NULL) {
        exit(1);
    }
    tcontact contacto;

    fread(&contacto, sizeof(tcontact), 1, arch);
    while (!feof(arch)) {
        printf("%s %d\n", contacto.nombre, contacto.numero);
        fread(&contacto, sizeof(tcontact), 1, arch);
    }
    fclose(arch);
}

void serch() {
    FILE *arch;
    char cod[40];
    tcontact contacto;
    bool existe = false;

    arch = fopen("agenda.dat", "rb");
    if (arch == NULL) {
        exit(1);
    }
    printf("Ingresa el nombre del contacto a consultar: ");
    scanf("%s", cod);

    fread(&contacto, sizeof(tcontact), 1, arch);
    while (!feof(arch)) {
        if (strcmp(cod, contacto.nombre) == 0) {
            printf("%s %d\n", contacto.nombre, contacto.numero);
            existe = true;
            break;
        }
        fread(&contacto, sizeof(tcontact), 1, arch);
    }
    if (!existe) {
        printf("No existe un contacto con dicho nombre\n");
    }

    fclose(arch);
}

void change() {
    FILE *arch;
    char cod[40];
    tcontact contacto;
    bool existe = false;

    arch = fopen("agenda.dat", "r+b");
    if (arch == NULL) {
        exit(1);
    }
    printf("Ingresa el nombre de contacto a modificar: ");
    scanf("%s", cod);

    fread(&contacto, sizeof(tcontact), 1, arch);
    while (!feof(arch)) {
        if (strcmp(cod, contacto.nombre) == 0) {
            printf("%s %d\n", contacto.nombre, contacto.numero);

            printf("Ingresa el nuevo numero: ");
            scanf("%d", &contacto.numero);

            int posicion = ftell(arch) - sizeof(tcontact);
            fseek(arch, posicion, SEEK_SET);
            fwrite(&contacto, sizeof(tcontact), 1, arch);
            printf("Se modifico el numero del contacto\n");

            existe = true;
            break;
        }
        fread(&contacto, sizeof(tcontact), 1, arch);
    }
    if (!existe) {
        printf("No existe un contacto con ese nombre\n");
    }
    fclose(arch);
}

void delete() {
    FILE *arch;
    FILE *temp;
    char cod[40];
    tcontact contacto;
    bool existe = false;

    arch = fopen("agenda.dat", "rb");
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

    printf("Ingresa el nombre del contacto que deseas eliminar: ");
    scanf("%s", cod);

    while (fread(&contacto, sizeof(tcontact), 1, arch) == 1) {
        if (strcmp(cod, contacto.nombre) != 0) {
            fwrite(&contacto, sizeof(tcontact), 1, temp);
        } else {
            existe = true;
        }
    }

    fclose(arch);
    fclose(temp);

    if (!existe) {
        remove("temp.dat");
        printf("No existe el contacto con ese nombre\n");
    } else {
        remove("agenda.dat");
        rename("temp.dat", "agenda.dat");
        printf("Contacto eliminado con éxito\n");
    }
}

int main() {
    int opcion;
    do {
        printf("1 - Crear un archivo binario llamado \"agenda.dat\"\n");
        printf("2 - Cargar un nuevo contacto a la agenda\n");
        printf("3 - Ver contactos almacenados\n");
        printf("4 - Consultar un contacto por su nombre\n");
        printf("5 - Modificar número telefónico\n");
        printf("6 - Eliminar un contacto de la agenda\n");
        printf("7 - Finalizar\n\n");

        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                create();
                break;
            case 2:
                load();
                break;
            case 3:
                list();
                break;
            case 4:
                serch();
                break;
            case 5:
                change();
                break;
            case 6:
                delete();
                break;
            default:
                break;
        }
    } while (opcion != 7);

    return 0;
}