#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TOTAL 1

int main(){
    struct paciente{
        char nombre[20];
        char apellido[10];
        int edad;
        char enfermedades[20];
        char temp[20];
    }registro[TOTAL];

    for(int i = 0; i<TOTAL; i++){
        int tam = 0;
        char temp[20] = "";

        printf("Registro del paciente: #%d\n", i+1);

        printf("Ingresa el nombre del paciente: \n");
        scanf("%s", &registro[i].nombre[0]);

        printf("Ingresa el apellido del paciente: \n");
        scanf("%s", &registro[i].apellido[0]);

        printf("Ingresa la edad del paciente: \n");
        scanf("%d", &registro[i].edad);

        
        do{
            fflush();
            int cont = 1;
            char temp[20] = "";
            printf("¿Cual es la %da enfermadad del paciente? (Si ya no tiene mas enfermedades escribir ''NA'')\n", cont);
            scanf("%s", &temp);
            strcpy(registro->enfermedades[i], temp);
        } while (strcmp(temp, "NA") != 0);
    }

    for(int i = 0; i<TOTAL; i++){
        printf("Nombre: %s", registro[i].nombre);
    }


}