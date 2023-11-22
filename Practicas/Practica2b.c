#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL 5

struct paciente {
    char nombre[20];
    char apellido[10];
    int edad;
    char enfermedades[20][20];

};

int main() {
    struct paciente registro[TOTAL];

    for (int i = 0; i < TOTAL; i++) {
        printf("Registro del paciente: #%d\n", i + 1);

        printf("Ingresa el nombre del paciente: \n");
        scanf("%s", registro[i].nombre);

        printf("Ingresa el apellido del paciente: \n");
        scanf("%s", registro[i].apellido);

        printf("Ingresa la edad del paciente: \n");
        scanf("%d", &registro[i].edad);

        int cont = 0;
        do {
            printf("¿Cuál es la %da enfermedad del paciente? (Si ya no tiene más enfermedades escribir ''NA'')\n", cont + 1);
            scanf("%s", registro[i].enfermedades[cont]);
            cont++;
        } while (strcmp(registro[i].enfermedades[cont - 1], "NA") != 0);
    }

    int cont1 = 0;

    for (int i = 0; i < TOTAL; i++) {
        for(int j = 0; j < 20; j++){

            if(strcmp(registro[i].enfermedades[j], "covid") == 0){
                cont1+=1;
            }
        }
    }

    printf("%d pacientes tienen covid", cont1);

    return 0;
}
