/*
 * The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.
 * Find the sum of all numbers, less than one million, which are palindromic in
 * base 10 and base 2. (Please note that the palindromic number, in either base,
 * may not include leading zeroes).
 */

#include <stdio.h>
#include <stdlib.h>

int intToBinary(int num, char **binary);
int power(int x, int n);
int palindromic(char string[], int length);

int main() {
    int i, len, sum = 0;
    char str[6];
    for (i = 1; i < 1000000; i++) {
        len = sprintf(str, "%d", i);
        if ( palindromic(str, len) == 1 ) {
            char *binary;
            len = intToBinary(i, &binary);
            if ( palindromic(binary, len) == 1) {
                sum += i;
            }
            free(binary);
        }
    }
    
    printf("%d\n", sum);
}

int intToBinary(int num, char **binary) {
    // Get length of the binary of num
    int length = 1, currentNum = num;
    while (currentNum > 1) {
        length++;
        currentNum /= 2;
    }

    // Form binary string; going from MSB to LSB, if the MSB value fits in the
    // number, a '1' is placed; otherwise, a '0' is placed
    *binary = (char *) malloc((length+1) * sizeof(char));
    int i, bitValue = power(2, length-1);
    for (i = 0; i < length; i++) {
        if (num - bitValue >= 0) {
            num -= bitValue;
            (*binary)[i] = '1';
        }
        else {
            (*binary)[i] = '0';
        }
        bitValue /= 2;
    }
    (*binary)[length] = '\0';

    // Return the length of the binary string
    return length;
}

int power(int x, int n) {
    int i, result = 1;
    for (i = 0; i < n; i++)
        result *= x;
    return result;
}

int palindromic(char string[], int length) {
    int i, halfLength, palindromic = 1;

    if (length % 2 == 0) 
        halfLength = length / 2;
    else
        halfLength = (length / 2) + 1;

    for (i = 0; i < halfLength; i++) {
        if (string[i] != string[length-1 - i]) {
            palindromic = 0;
            break;
        }
    }

    return palindromic;
}
