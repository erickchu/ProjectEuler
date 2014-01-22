/*
 * A permutation is an ordered arrangement of objects. For example, 3124 is one
 * possible permutation of the digits 1, 2, 3 and 4. If all of the permutations
 * are listed numerically or alphabetically, we call it lexiographic order. The
 * lexicographic permutations of 0, 1 and 2 are:
 * 012 021 102 120 201 210
 * What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4,
 * 5, 6, 7, 8 and 9?
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM_DIGITS 10
#define LIMIT 1000000

void permute(int *digits, int index, int *counter, int **permutation);

int main() {
    // counter stores counted permutations and tracks the current perm term
    // digits[] holds a value of 1 if the index value hasn't been used in the
    // permutation and a 0 if the index is already being used in the permutation
    // perm holds the lexicographic permutation at the 'counter' term
	int i, digits[NUM_DIGITS], counter = 0;
    int *perm = (int *) malloc(NUM_DIGITS * sizeof(int));
	for (i = 0; i < NUM_DIGITS; i++)
		digits[i] = 1;

    // permute is a recursive function that uses backtracking to solve problem
	permute(digits, 0, &counter, &perm);
}

void permute(int *digits, int index, int *counter, int **permutation) {
	int i, j;

    // If the permutation is complete (all digits are used)
    if (index == NUM_DIGITS) {
        // Increment counter; counter also represents the permutation's number
        // in the lexicographic order
        (*counter)++;
        if (*counter == LIMIT) {
            printf("%d: ", *counter);
            for (i = 0; i < NUM_DIGITS; i++)
                printf("%d", (*permutation)[i]);
            printf("\n");
        }
    }
	
    // For each digit
    for (i = 0; i < NUM_DIGITS; i++) {
        // If the digit has yet to be used in the permutation
        if (digits[i] == 1) {
            // Copy the array to a new array but "use" the unused digit
            int *newDigits = (int *) malloc(NUM_DIGITS * sizeof(int));
            for (j = 0; j < NUM_DIGITS; j++) {
                newDigits[j] = digits[j];
            }
            newDigits[i] = 0;

            // Update the permutation to use the digit
            (*permutation)[index] = i;

            // Recurse
            permute(newDigits, index+1, counter, permutation);
        }

    }
}
