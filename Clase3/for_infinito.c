#include <stdio.h>

void main(){
    int i=0;

    for(;;){
        printf("For numero %d \n", i);

        if(i>10){
            break;
        }
        i+=1;
    }

    printf("\n Sali del for \n");
}