#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *archivo;
    char caracter;
    archivo = fopen("prueba.txt", "r");

    if(archivo == NULL){
        printf("Error al abrir el archivo");
    }else{
        printf("El contenido del archivo es: \n\n");
        while((caracter = fgetc(archivo)) != EOF){ // Todos los archivos terminan con un caracter "EOF"
            printf("%c", caracter);
        }
    }
    fclose(archivo); // Importante siempre cerrar el archivo.

    return 0;
}

/*
Relativa
    . file .. atras
    ./prueba.txt

    ../../prueba.txt

Absuluta.
    C://Alumno/Sebas/Documentos/programacion/practica2/prueba.txt

    *Evitar rutas absolutas en lo mas posible*
*/

/*
r -> lectura
w -> escritura
a -> abrir un archivo y escribe donde se quedo, si no existe lo crea
r+ -> lectura y escritura, el archivo debe existir
w+ -> archivo de lectura escritura, se crea si no existe o lo sobreescribe
rb -> lectura de archivo en modo binario
r+b o rb+ -> abre archivo en lectura escritura de binarios.
*/