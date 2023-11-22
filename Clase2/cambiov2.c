#include <stdio.h>

/*Programa que calcule cuanto cambio tienes que dar*/

void main(){
    float cantidad_original, monedas_20, monedas_10, monedas_5, monedas_2, monedas_1, monedas_0_50, sobrante;
    
    printf("¿Cual es la cantidad original? \n");
    scanf("%f", &cantidad_original);

cantidad_original = cantidad_original * 10;

    if (cantidad_original >= 200){
        monedas_20 = (int)(cantidad_original / 200);
        sobrante = ((int)(cantidad_original) % 200);
        printf("Monedas de 20: %f \n", monedas_20);
    } 
    if (sobrante >= 100){
        monedas_10 = (int)(sobrante / 100);
        sobrante = ((int)(sobrante) % 100);
        printf("Monedas de 10: %f \n", monedas_10);
    }
    if (sobrante >= 50){
        monedas_5 = (int)(sobrante / 50);
        sobrante = ((int)(sobrante) % 50);
        printf("Monedas de 5: %f \n", monedas_5);
    }
    if (sobrante >= 20){
        monedas_2 = (int)(sobrante / 20);
        sobrante = ((int)(sobrante) % 20);
        printf("Monedas de 2: %f \n", monedas_2);
    }
    if (sobrante >= 10){
        monedas_1 = (int)(sobrante / 10);
        sobrante = ((int)(sobrante) % 10);
        printf("Monedas de 1: %f \n", monedas_1);
    }
    if (sobrante >= 5){
        monedas_0_50 = (int)((sobrante) / 5);
        sobrante = ((int)(sobrante) % 5);
        printf("Monedas de 0.50: %f \n", monedas_0_50);
    }

    return 0;

}