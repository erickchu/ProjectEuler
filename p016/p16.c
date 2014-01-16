/*
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 * What is the sum of the digits of the number 2^1000?
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    double number = pow(2.0, 1000.0);   // 2^1000
    int numDigits = log10(number) + 1;  // number of digits is log10(number) + 1

    // Store the number as a string
    char numberStr[numDigits];
    snprintf(numberStr, numDigits+1, "%lf", number);

    // Add each digit's value to the overall sum
    int i, sum = 0;
    for (i = 0; i < numDigits; i++) 
        sum += numberStr[i] - '0';

    printf("%d\n", sum);
}

