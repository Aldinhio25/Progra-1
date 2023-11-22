#include <stdio.h>
#include <stdlib.h>
#define TOTAL 500

int main(){
    struct alumno{
        char nombre[20];
        char apellido[10];
        int edad;
        int nota[4];
        float promedio;
    }registro[TOTAL];

    for(int i = 0; i<TOTAL; i++){
        registro[i].promedio=0;
        int acumulado = 0;
        printf("Informacion del alumno %d: \n\n", i+1);

        printf("Ingresa el nombre del alumno: \n");
        scanf("%s", &registro[i].nombre[0]);

        printf("Ingresa el apellido del alumno: \n");
        scanf("%s", &registro[i].apellido[0]);

        printf("Ingresa la edad del alumno: \n");
        scanf("%s", &registro[i].edad);

        for(int j = 0; j<4; j++){
            printf("Ingresa la nota %d del alumno: \n", j+1);
            scanf("%s", &registro[i].nota[j]);
            acumulado += registro[i].nota[j];
        }

        registro[i].promedio = (float)acumulado/4;
        
    }
}