#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *archivo;
    char cadena[] = "Esto lo estoy escribiendo desde el codigo";
    archivo = fopen("prueba2.txt", "a");

    if(archivo == NULL){
        printf("Error al abrir el archivo");
    }else{
        fwrite(cadena, sizeof(char), sizeof(cadena), archivo);
    }
    fclose(archivo);
    return 0;
}