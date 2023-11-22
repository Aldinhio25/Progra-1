#include<stdio.h>

void main(){
    char minuscula, mayuscula;

    printf("Introduce un caracter en minuscula \n");
    scanf("%c", &minuscula);

    mayuscula = minuscula - 32;
    printf("El caracter de %c en mayuscula es %c \n", minuscula, mayuscula);
}