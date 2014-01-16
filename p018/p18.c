/*
 * By starting at the top of the triangle below and moving to adjacent numbers
 * on the row below, the maximum total from top to bottom is 23.
 * 3
 * 7 4
 * 2 4 6
 * 8 5 9 3
 * That is, 3 + 7 + 4 + 9 = 23.
 * Find the maximum total from top to bottom of the triangle below (See
 * 'triangle.txt')
 * NOTE: As there are only 16384 routes, it is possible to solve this problem by
 * trying every route. However, Problem 67, is the same challenge with a
 * triangle containing one-hundred rows; it cannot be solved by brute force, and
 * requires a clever method! ;o)
 */

#include <stdio.h>
#include <stdlib.h>

#define TRIANGLE_LEN 15     // Length of a side of the triangle

void initializeTriangle(int ***tri);
void readFile(int ***tri, char *fileName);
void setupInitialSums(int ***sums, int ***values);
void findSums(int ***sums, int ***values);

int main() {
    // Set up two 3D "triangle" arrays; given row i and col j,
    // triValues[i][j] is the value at (i, j)
    // triSums[i][j] is the max possible sum from a "triangle" starting at (i,j)
    int **triValues, **triSums;

    // Use dynamic programming going from the bottom up
    // See setupInitialSums(...) and findSums(...) for more information
    initializeTriangle(&triValues);
    initializeTriangle(&triSums);
    readFile(&triValues, "triangle.txt");
    setupInitialSums(&triSums, &triValues);
    findSums(&triSums, &triValues);
    printf("%d\n", triSums[0][0]);
}

// Initialize a 3D "triangle" array; the amount of values in each row of the
// triangle should be equal to where that row is on the triangle (e.g. the 7th
// row of the triangle has 7 values)
void initializeTriangle(int ***tri) {
    int i, j;
    *tri = (int **) malloc((TRIANGLE_LEN) * sizeof(int *));
    for (i = 0; i < TRIANGLE_LEN; i++)
        (*tri)[i] = (int *) malloc(i * sizeof(int));
}

// Read file containing triangle values, store in triangle array
void readFile(int ***tri, char *fileName) {
    FILE *fp = fopen(fileName, "r");
    int i, j;
    for (i = 0; i < TRIANGLE_LEN; i++) 
        for (j = 0; j <= i; j++)
            fscanf(fp, "%d", &(*tri)[i][j]);
    fclose(fp);
}

// Setup the triangle sums array; the values of the bottom row of the sums
// triangle is equal to the values of the values triangle, as there is no
// triangle that can be formed below it
void setupInitialSums(int ***sums, int ***values) {
    int i;
    for (i = 0; i < TRIANGLE_LEN; i++) 
        (*sums)[TRIANGLE_LEN-1][i] = (*values)[TRIANGLE_LEN-1][i];
}

// Going from the bottom to the top starting with the second-to-last row, find
// the maximum possible triangle sum at (i, j) by adding the value at (i, j)
// with the maximum possible sum from the two triangles below it
void findSums(int ***sums, int ***values) {
    int i, j;
    for (i = TRIANGLE_LEN-2; i >= 0; i--) {
        for (j = 0; j <= i; j++) {
            (*sums)[i][j] = 
                (*values)[i][j] + max((*sums)[i+1][j],(*sums)[i+1][j+1]);
        }
    }
}

void printTriangle(int ***tri) {
    int i, j;
    for (i = 0; i < TRIANGLE_LEN; i++) {
        for (j = 0; j <= i; j++)
            printf("%d ", (*tri)[i][j]);
        printf("\n");
    }
}

int max(int a, int b) {
    if (a < b)
        return b;
    else
        return a;
}
