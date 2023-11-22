#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *archivo;
    char caracter;
    archivo = fopen("prueba3.txt", "a");

    if(archivo == NULL){
        printf("Error al abrir el archivo");
    }else{
        printf("Introduce un texto al archivo: "); //archivo==fichero
        while((caracter = getchar()) != '\n'){
            printf(", %c", fputc(caracter, archivo));
        }
    }
    fclose(archivo);
    return 0;
}