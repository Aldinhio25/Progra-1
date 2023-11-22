#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

int main(){
    char winner=' ';
    char respuesta_humano;
    int int_respuesta_maquina;

    do{
        printf("que quieres tirar");
        printf("r para roca | p para papel | t para tijeras | s para spock | l para lagarto");
        scanf("%c", &respuesta_humano);
        respuesta_humano = toupper(respuesta_humano);

        srand(time(NULL));
        int_respuesta_maquina = (rand()/5)+1


        switch{
            case 0:
                if(respuesta_humano == "P" | respuesta_humano == "S"){
                    printf("Gano el humano");
                } else if(respuesta_humano == "R") {
                    printf("Empate")
                } else {
                    printf("Gano la maquina");
                }
            case 1:
                if()
        }

    }
}
