/*
 * The Fibonacci sequence is defined by the recurrence relation:
 * Fn = Fn-1 + Fn-2, where F1 = 1 and F2 = 1.
 * Hence the first 12 terms will be:
 * F1 = 1
 * F2 = 1
 * F3 = 2
 * F4 = 3
 * F5 = 5
 * F6 = 8
 * F7 = 13
 * F8 = 21
 * F9 = 34
 * F10 = 55
 * F11 = 89
 * F12 = 144
 * The 12th term, F12, is the first term to contain three digits.
 * What is the first term in the Fibonacci sequence to contain 1000 digits?
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM_DIGITS 1000

int main() {
    int i;
    char buffer[2];

    // Initialize fibonacci terms as strings where each char represents a digit
    char *f1 = (char *) malloc(NUM_DIGITS * sizeof(char));
    char *f2 = (char *) malloc(NUM_DIGITS * sizeof(char));
    for (i = 0; i < NUM_DIGITS; i++) {
        f1[i] = '0';
        f2[i] = '0';
    }
    f1[NUM_DIGITS-1] = '1';
    f2[NUM_DIGITS-1] = '1';

    // While the first digit is a 0, the term has yet to hit 1000 digits
    int sum, carryOver = 0, term = 2;
    while (f2[0] - '0' == 0) {
        term++;
        for (i = NUM_DIGITS-1; i >= 0; i--) {
            sum = (f1[i]-'0') + (f2[i]-'0') + carryOver;
            sprintf(buffer, "%02d", sum);
            carryOver = buffer[0] - '0';
            f1[i] = f2[i];
            f2[i] = buffer[1];
        }
    }
    
    printf("%d\n", term);
}
