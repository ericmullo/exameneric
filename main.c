#include <stdio.h>
#include "maze.h"
#include "player.h"
//Creditos: Eric Mullo

void juegoNuevo() {
    char input;
    int gameOver = 0;

    printf("\n-- JUEGO NUEVO --\n");
    printf("Instrucciones:\n");
    printf("Utiliza las teclas 'w' (arriba), 's' (abajo), 'a' (izquierda), 'd' (derecha) para moverte por el laberinto.\n");
    printf("Presiona 'q' para regresar al menú principal.\n");

    while (!gameOver) {
        printMaze();
        printf("\nMovimientos realizados: %d\n", getMoveCount());

        scanf(" %c", &input);

        if (input == 'q') {
            break;
        }

        movePlayer(input);

        if (hasWon()) {
            printf("\n¡Felicidades! Has llegado a la meta.\n");
            int moveCount = getMoveCount();
            if (moveCount <= 8) {
                printf("Eres un Pro!\n");
            } else if (moveCount <= 15) {
                printf("Eres novato\n");
            } else {
                printf("Eres un noob!\n");
            }
            gameOver = 1;
        }
    }
}

int main() {
    int option;
    while (1) {
        printf("----- MENU -----\n");
        printf("1. Juego nuevo\n");
        printf("2. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &option);

        if (option == 1) {
            juegoNuevo();
        } else if (option == 2) {
            break;
        } else {
            printf("Opción inválida. Intente nuevamente.\n");
        }
    }

    return 0;
}

