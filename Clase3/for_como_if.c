#include <stdio.h>

void main(){
    int digito=0,vueltas=0;

    for(;digito<=9;){
        printf("%d \n", digito++);
        vueltas++;
    }

    printf("%d \n", vueltas);

    /*Dentro de este for no estamos declarando las variables ni tampoco
    estamos sumando nada, solo estamos usando la funcion que tiene como IF*/

}