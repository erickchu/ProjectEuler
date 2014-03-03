/*
 * The number 3797 has an interesting property. Being prime itself, it is
 * possible to continuously remove digits from left to right, and remain prime
 * at each stage: 3797, 797, 97, and 7. Similarly, we can work from right to
 * left: 3797, 379, 37, 3.
 * Find the sum of the eleven primes that are both truncatable from left to
 * right and right to left. 
 * NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000
#define NUM_PRIMES 11

char number[MAX] = "";

int main() {
    // The leftmost digit has to be 2, 3, 5, or 7
    // The rightmost digit has to be 3 or 7

    // Sieve of Erathosthenes to find primes below 1000000
    int p = 2, multiple, len, sum = 0, count = 0;
    while (count != NUM_PRIMES) {
        if (number[p] == 0) {
            number[p] = 2;
            len = numLength(p);
            if ((len > 1) && (truncLtoR(p,len) > 0) && (truncRtoL(p,len) > 0)) {
                sum += p;
                count++;
            }
            multiple = p * 2;
            while (multiple < MAX) {
                number[multiple] = 1;
                multiple += p;
            }
        }
        p++;
    }

    printf("%d\n", sum);
}

int numLength(int num) {
    if (num < 0) return 0;
    if (num < 10) return 1;
    if (num < 100) return 2;
    if (num < 1000) return 3;
    if (num < 10000) return 4;
    if (num < 100000) return 5;
    if (num < 1000000) return 6;
    else return 7;
}

int truncLtoR(int num, int length) {
    char numStr[length], truncatedStr[length];
    sprintf(numStr, "%d", num);

    int i, j, k, p;
    for (i = 0; i < length; i++) {
        strcpy(truncatedStr, "");
        for (k = 0, j = i; j < length; j++, k++)
            truncatedStr[k] = numStr[j];
        while (k < length)
            truncatedStr[k++] = ' ';
        truncatedStr[k] = '\0';
        p = strtol(truncatedStr, NULL, 10);
        if (number[p] != 2)
            return 0;
    }

    return 1;
}

int truncRtoL(int num, int length) {
    char numStr[length], truncatedStr[length];
    sprintf(numStr, "%d", num);

    int i, j, p;
    for (i = length; i > 0; i--) {
        strcpy(truncatedStr, "");
        strncat(truncatedStr, numStr, i);
        p = strtol(truncatedStr, NULL, 10);
        if (number[p] != 2)
            return 0;
    }

    return 1;
}
