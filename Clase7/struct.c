#include <stdio.h>

struct alumno{
    char nombre[20];
    char apellido[10];
    int edad;
    int nota[4];
    float promedio;
};

int main(){
    int acumulado=0;

    struct alumno alumno_1 = {"Raul", "Perez", 20};
    for(int i = 0; i<4; i++){
        printf("ingresa la nota %d ", i+1);
        scanf("%d", &alumno_1.nota[i]);
        acumulado += alumno_1.nota[i];
    }
    alumno_1.promedio = (float)acumulado/4;
    printf("El promedio del alumno %s %s, es %f", alumno_1.nombre, alumno_1.apellido, alumno_1.promedio);
}