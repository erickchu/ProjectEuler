/*
 * In the 20x20 grid below, four numbers along a diagonal line have been marked
 * in red.
 * The product of these numbers is 26 x 63 x 78 x 14 = 1788696.
 * What is the greatest product of four adjacent numbers in the same direction
 * (up, down, left, right, or diagonally) in the 20x20 grid? (See 'grid.txt')
 */

#include <stdio.h>
#include <stdlib.h>

#define GRID_ROWS 20
#define GRID_COLS 20

void initializeGrid(int ***grid);
void readGridFile(int ***grid, char *fileName);
void printGrid(int ***grid);
void scanHorizontalAdjacent(int ***grid, int *product);
void scanVerticalAdjacent(int ***grid, int *product);
void scanDiagonalLR(int ***grid, int *product);
void scanDiagonalRL(int ***grid, int *product);

int main() {
    int **grid, product = 1;
    char *gridFile = "grid.txt";

    initializeGrid(&grid);
    readGridFile(&grid, gridFile);
    scanHorizontalAdjacent(&grid, &product);
    scanVerticalAdjacent(&grid, &product);
    scanDiagonalLR(&grid, &product);
    scanDiagonalRL(&grid, &product);

    printf("%d\n", product);
}

void initializeGrid(int ***grid) {
    int i;
    *grid = (int **) malloc(GRID_ROWS * sizeof(int *));
    for (i = 0; i < GRID_ROWS; i++)
        (*grid)[i] = (int *) malloc(GRID_COLS * sizeof(int));
}

void readGridFile(int ***grid, char *fileName) {
    int x, y;
    FILE *fp = fopen(fileName, "r");
    for (x = 0; x < GRID_ROWS; x++)
        for (y = 0; y < GRID_COLS; y++)
            fscanf(fp, "%d", &(*grid)[x][y]);
    fclose(fp);
}

void printGrid(int ***grid) {
    int i, j;
    for (i = 0; i < GRID_ROWS; i++) {
        for (j = 0; j < GRID_COLS; j++) 
            printf("%d ", (*grid)[i][j]);
        printf("\n");
    }
}

void scanHorizontalAdjacent(int ***grid, int *product) {
    int x, y, adjNum[4];
    for (x = 0; x < GRID_ROWS; x++) {
        for (y = 0; y < GRID_COLS; y++) {
            if (y < 4) {
                adjNum[y] = (*grid)[x][y];
            }
            else {
                *product = max(productOfIntArray(adjNum, 4), *product);
                adjNum[0] = adjNum[1];
                adjNum[1] = adjNum[2];
                adjNum[2] = adjNum[3];
                adjNum[3] = (*grid)[x][y];
            }
        }
    }
}

void scanVerticalAdjacent(int ***grid, int *product) {
    int x, y, adjNum[4];
    for (y = 0; y < GRID_COLS; y++) {
        for (x = 0; x < GRID_ROWS; x++) {
            if (x < 4) {
                adjNum[x] = (*grid)[x][y];
            }
            else {
                *product = max(productOfIntArray(adjNum, 4), *product);
                adjNum[0] = adjNum[1];
                adjNum[1] = adjNum[2];
                adjNum[2] = adjNum[3];
                adjNum[3] = (*grid)[x][y];
            }
        }
    }
}

void scanDiagonalLR(int ***grid, int *product) {
    int x, y, adjNum[4];

    // Start from the top left corner and move right then down
    for (x = 0; x < GRID_ROWS-3; x++) {
        for (y = 0; y < GRID_COLS-3; y++) {
            adjNum[0] = (*grid)[x][y];
            adjNum[1] = (*grid)[x+1][y+1];
            adjNum[2] = (*grid)[x+2][y+2];
            adjNum[3] = (*grid)[x+3][y+3];
            *product = max(productOfIntArray(adjNum, 4), *product);
        }
    }
}

void scanDiagonalRL(int ***grid, int *product) {
    int x, y, adjNum[4];
    
    // Start from the top right corner and move left then down
    for (x = 0; x < GRID_ROWS-3; x++) {
        for (y = GRID_COLS-1; y > 3; y--) {
            adjNum[0] = (*grid)[x][y];
            adjNum[1] = (*grid)[x+1][y-1];
            adjNum[2] = (*grid)[x+2][y-2];
            adjNum[3] = (*grid)[x+3][y-3];
            *product = max(productOfIntArray(adjNum, 4), *product);
        }
    }
}

int max(int a, int b) {
    if (a < b)
        return b;
    else
        return a;
}


int productOfIntArray(int array[], int size) {
    int i, product = 1;
    for (i = 0; i < size; i++) {
        product *= array[i];
    }
    return product;
}
