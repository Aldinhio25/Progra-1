#include <stdio.h>

int cuadrado(int);
int maximo(int, int, int);
int maximo_array(int[]);

int main(){
    
    int array[] = {30,40,120,20,25,80,200,2};

    printf("%d\n", maximo(30,8,6));
    printf("%d\n", maximo_array(array));

}

int maximo(int x, int y, int z){
    int max = x;
    if(y>max) max=y;
    if(z>max) max=z;
    return max;
}

int maximo_array(int x[]){
    int temp = 0;
    for(int i=0; i<8; i++){
        if(x[i] > temp){
            temp = x[i];
        }    
    }

    return temp;
}