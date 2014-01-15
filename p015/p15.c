/*
 * Starting in the top left corner of a 2x2 grid, and only being able to move to
 * the right and down, there are exactly 6 routes to the bottom right corner.
 * How many such routes are there through a 20x20 grid?
 */

#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 20

void initializeGrid(long long ***grid);
void setupGrid(long long ***grid);
void findPaths(long long ***grid);

int main() {
    // Let the top-left corner be located at row = 0, col = 0 and the 
    // bottom-right corner be at row = GRID_SIZE, col = GRID_SIZE
    long long **grid;

    // Dynamic programming 
    initializeGrid(&grid);
    setupGrid(&grid);
    findPaths(&grid);
    printf("%lld\n", grid[0][0]);
}

// grid is a 3D array where each value grid[i][j] is equal to the number of
// possible paths to reach the bottom corner from row i, column j
void initializeGrid(long long ***grid) {
    int i, j;
    *grid = (long long **) malloc((GRID_SIZE+1) * sizeof(long long *));
    for (i = 0; i < GRID_SIZE+1; i++) {
        (*grid)[i] = (long long *) malloc((GRID_SIZE+1) * sizeof(long long));
    }
}

// Setup initial values of the grid
void setupGrid(long long ***grid) {
    // If we are on the bottom or right end of the grid, there is only one
    // possible path from that point to the bottom-right corner
    int i;
    for (i = 0; i < GRID_SIZE; i++) {
        (*grid)[i][GRID_SIZE] = 1;
        (*grid)[GRID_SIZE][i] = 1;
    }

    // There are no possible moves at the bottom-right corner (i.e. destination)
    (*grid)[GRID_SIZE][GRID_SIZE] = 0;
}

// The number of possible paths from each point (i, j) is equal to the sum of
// the number of paths of the possible "next" points ((i, j+1), (i+1, j))
void findPaths(long long ***grid) {
    int i, j;
    for (i = GRID_SIZE-1; i >= 0; i--) {
        for (j = GRID_SIZE-1; j >= 0; j--) {
            (*grid)[i][j] = (*grid)[i+1][j] + (*grid)[i][j+1];
        }
    }
}
