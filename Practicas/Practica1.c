#include<stdio.h>

void main(){
    int opcion=0;
    int *pe;
    int tam;
    int f;
    int sorted;

    printf("¿Cuantos numeros quieres ordenar? \n");
    scanf("%d", &tam);
    pe = malloc(tam*sizeof(int));

    for(int i=0; i<tam;i++){
        printf("Ingresa un numero \n");
        scanf("%d", &pe[i]);
    }    

    while(opcion != 3){
        printf("¿Como quieres ordenar los numeros? \n");

        printf("1. De mayor a menor.\n");
        printf("2. De menor a mayor\n");
        printf("3. Salir\n");

        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                for(int i=0; i<tam-1; i++){
                    for(int j=0; j<tam-i-1; j++){
                        if(pe[j] < pe[j+1]){
                            int aux = pe[j];
                            pe[j] = pe[j+1];
                            pe[j+1] = aux;
                        }
                    }
                }
                break;
            case 2:
                for(int i=0; i<tam-1; i++){
                    int min = i;
                    for(int j=i+1; j<tam; j++){
                        if(pe[j] < pe[min]){
                            min = j;
                        }
                    }
                    int aux = pe[i];
                    pe[i] = pe[min];
                    pe[min] = aux;
                }
                break;
            case 3: 
                break;

            default:
                printf("Opcion Incorrecta \n");
                break;
        }


        for (int i = 0; i < tam; i++) {     
            printf("%d ", pe[i]);     
        } 
    }
}