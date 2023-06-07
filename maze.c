#include <stdio.h>
#include "maze.h"

#define ROWS 5
#define COLS 5

int maze[ROWS][COLS] = {
    {0, 1, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}
};

void printMaze() {
    printf("Laberinto:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int isValidMove(int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        if (maze[row][col] == 0) {
            return 1;
        }
    }
    return 0;
}
