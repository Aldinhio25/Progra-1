#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER ='X';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpace();
void playerMove();
void computerMove();
void printWinner(char);

/*
Miembros del equipo:
    - Rodriguez Blanco Julio Joshua
    - Luna Martinez Escobar Guillermo
    - Barcenas Gonzalez Sebastian Amadeus
*/

/*
Metodo que limpia el tablero
*/
void resetBoard(){
    for (int i=0; i<3;i++){
        for (int j=0;j<3;j++)
        board[i][j] = ' ';
    }
}

void printBoard(){
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkFreeSpace(){
    int freeSpace = 9;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if(board[i][j] != ' '){
                freeSpace--;
            }
        }
    }
}

void playerMove(){
    int x, y;
    do{
        printf("Introduce fila #(1-3): ");
        scanf("%d", &x);
        x--;
        printf("Introduce columna #(1-3): ");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' '){
            printf("Movimiento no permitido!!!\n");
        }else{
            board[x][y] = PLAYER;
            break;
        }
    }while(board[x][y] != ' ');
}

void computerMove(){
    srand(time(0));
    int x, y;
    if(checkFreeSpace()>0){
        do{
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');
        board[x][y] = COMPUTER;
    }else{
        printWinner(' ');
    }
}

int checkWinner(){
    //check rows o filas
    for (int i=0; i<3; i++){
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            return board[i][0];
        }
    }

    //check de columnas
    for (int i=0; i<3; i++){
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            return board[0][i];
        }
    }

    //check de diagonales
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]){
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]){
        return board[0][2];
    }

    return ' ';
}

void printWinner(char winner){
    if(winner == PLAYER){
        printf("GANASTE!!!");
    }
    else if(winner == COMPUTER){
        printf("YOU LOSE!!!");
    }else{
        printf("GATO!!!");
    }
}
    

int main(){
    char winner = ' ';
    char respuesta = ' ';

    do{
        char winner = ' ';
        char respuesta = ' ';
        resetBoard();

        while (winner == ' ' && checkFreeSpace != 0){
            printBoard();

            playerMove();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpace() == 0){
                break;
            }

            computerMove();
            winner = checkWinner();
                        if(winner != ' ' || checkFreeSpace() == 0){
                break;
            }
        }
        printBoard();
        printWinner(winner);
        fflush(stdin);

        printf("\nQuieres jugar de nuevo? (Y/N): ");
        scanf("%c", &respuesta);
        respuesta = toupper(respuesta);
    } while (respuesta == 'Y');

    printf("Gracias por jugar");
    return 0;
}