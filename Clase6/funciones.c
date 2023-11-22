#include <stdio.h>

int cuadrado(int);

int main(){
    int x;
    int y;
    for(x=0; x<=10; x++){
        printf("%d\n", cuadrado(x));
    }
}

int cuadrado(int y){
    return y*y;
}