/*
 * In England the currency is made up of pound, £, and pence, p, and there are 
 * eight coins in general circulation:
 *
 * 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
 * It is possible to make £2 in the following way:
 *
 * 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
 * How many different ways can £2 be made using any number of coins?
 */

#include <stdio.h>
#include <stdlib.h>

#define TOTAL 200
#define NUM_DENOMS 8

int denoms[] = { 1, 2, 5, 10, 20, 50, 100, 200 };

int main() {
    // Use a dynamic programming approach to solve problem; setup 3D array
    // array[i][j] is the number of ways to make up i+1 using coins of
    // denominations of less than or equal to denoms[j]
    int i, j, **array = (int **) malloc((TOTAL+1) * sizeof(int *));
    for (i = 0; i < TOTAL+1; i++)
        array[i] = (int *) malloc(NUM_DENOMS * sizeof(int));

    // Initialize the first column; there is only a single way (no more, no
    // less) to make up any value using the denomination 1p
    for (i = 0; i < TOTAL+1; i++)
        array[i][0] = 1;

    // Initialize the first row; there is only a single way to make up the value
    // '1' regardless of the denominations of coins used
    for (j = 0; j < NUM_DENOMS; j++)
        array[1][j] = 1;

    // To make up each value i
    for (i = 1; i < TOTAL+1; i++) {
        // Using coins of denoms[j] and less
        for (j = 1; j < NUM_DENOMS; j++) {
            // The ways to make up the value i using coins of denoms[j] and less
            // is at least the same as the ways to do so using coins of
            // denoms[j-1] and less
            array[i][j] = array[i][j-1];

            // If a coin of denoms[j] fits exactly into value i, then using that
            // coin only provides 1 extra way to make up value i
            if (denoms[j] == i)
                array[i][j] += 1;
            // Otherwise, if the (value i - a coin of denoms[j]) would result in
            // change 'c' > 0, we would also add the number of ways to make up
            // 'c' with coins of denoms[j] and less
            else if (denoms[j] < i) {
                array[i][j] += array[ i-denoms[j] ][j];
            }
        }
    }

    printf("%d\n", array[TOTAL][NUM_DENOMS-1]);
}
