#include<stdio.h>
#include<stdlib.h>

void main(){
    int *pe;
    int tam;
    int f;
    printf("Cuantos elementos quieres: ");
    scanf("%d", &tam);
    pe = malloc(tam*sizeof(int));

    for(int i=0; i<tam;i++){
        printf("Ingresa un numero \n");
        scanf("%d", &pe[i]);
    }

    printf("%d \n", pe);
    free(pe);
}