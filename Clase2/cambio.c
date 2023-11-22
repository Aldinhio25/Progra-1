#include <stdio.h>

/*Programa que calcule cuanto cambio tienes que dar*/

void main(){
    float cantidad_original, monedas_20, monedas_10, monedas_5, monedas_2, monedas_1, monedas_0_50, sobrante;
    
    printf("¿Cual es la cantidad original?");
    scanf("%f", &cantidad_original);
/*
    monedas_20 = cantidad_original / 20;
    monedas_10 = cantidad_original / 10;
    monedas_5 = cantidad_original / 5;
    monedas_2 = cantidad_original / 2;
    monedas_1 = cantidad_original / 1;
    monedas_0_50 = cantidad_original / 0.50;
*/
    if (cantidad_original >= 20){
        monedas_20 = (int)(cantidad_original / 20);
        sobrante = ((int)(cantidad_original) % 20);
        printf("Monedas de 20: %f \n", monedas_20);
    } 
    if (sobrante >= 10){
        monedas_10 = (int)(sobrante / 10);
        sobrante = ((int)(sobrante) % 10);
        printf("Monedas de 10: %f \n", monedas_10);
    }
    if (sobrante >= 5){
        monedas_5 = (int)(sobrante / 5);
        sobrante = ((int)(sobrante) % 5);
        printf("Monedas de 5: %f \n", monedas_5);
    }
    if (sobrante >= 2){
        monedas_2 = (int)(sobrante / 2);
        sobrante = ((int)(sobrante) % 2);
        printf("Monedas de 2: %f \n", monedas_2);
    }
    if (sobrante >= 1){
        monedas_1 = (int)(sobrante / 1);
        sobrante = ((int)(sobrante) % 1);
        printf("Monedas de 1: %f \n", monedas_1);
        printf("El sobrante es: %f", sobrante);
    }
    if (sobrante >= 5){
        monedas_0_50 = (int)((sobrante * 10) / 5);
        sobrante = ((int)(sobrante) % 5);
        printf("Monedas de 0.50: %f \n", monedas_0_50);
    }

  /*  printf("Monedas de 20$: %f \n Monedas de 10$: %f \n Monedas de 5$: %f \n Monedas de 2$: %f \n Monedas de 1$: %f \n Monedas de 0.50$: %f \n", monedas_20, monedas_10, monedas_5, monedas_2, monedas_1, monedas_0_50);
*/
    
}