#include <stdio.h>
#include <stdlib.h>

int main(){
    char c;

    do
    {
        fflush(stdin);
        printf("Introduce una vocal o 's' para salir: \n");
        scanf("%c", &c);

        switch(c){
            case 'a':
                printf("De Arbol \n");
                break;
            case 'e':
                printf("de Elefante \n");
                break;
            case 'i':
                printf("de Indio \n");
                break;
            case 'o':
                printf("de Oso \n");
                break;
            case 'u':
                printf("de Ultimo \n");
                break;
            default:
                printf("Eso no es una vocal \n");
                break;
        }
        fflush(stdin);
    } while (c!='s');
    

}