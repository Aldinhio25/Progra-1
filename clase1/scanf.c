#include <stdio.h>
/*Precio Neto = Precio Coste * 100 + Margen / 100*/

void main(){
    float precio_neto, precio_coste, margen;

    printf("¿Cual es el precio coste?");
    scanf("%f", &precio_coste);

    printf("¿Cual es el margen?");
    scanf("%f", &margen);

    precio_neto = precio_coste * (100 + margen)/100;
    
    printf("El precio neto es %f \n", precio_neto);
}