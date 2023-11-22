#include <stdio.h>

int main(){
    printf("%d\n", factorial(5));
    printf("%d\n", factorial_recursivo(5));
}

int factorial(int x){
    int temp = x;
    for(int i =x ;i>1;i--){
        temp = temp * (i-1);
    }
    return temp;
}

int factorial_recursivo(int x){
    if(x<1){
        return 1;
    }
    return x * factorial (x-1);
}