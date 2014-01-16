/*
 * n! means n x (n-1) x ... x 3 x 2 x 1
 * For example, 10! = 10 x 9 x ... x 3 x 2 x 1 = 3628800, and the sum of the
 * digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 * Find the sum of the digits in the number 100!
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUMBER 100

double factorial(int n);
char getFactorialString(char **str, int len);

int main() {
    // The value returned by factorial(NUMBER) is too large to be precisely
    // stored, hence we only use it to find the number of digits in the value
    int numDigits = log10( factorial(NUMBER) ) + 1;  
    
    // Store the value as a string
    char *numberStr;
    getFactorialString(&numberStr, numDigits);
    
    // Get the sum of each digit in the string
    int i, sum = 0;
    for (i = 0; i < numDigits; i++)
        sum += numberStr[i] - '0';

    printf("%d\n", sum);
}

double factorial(int n) {
    double product = 1;
    int i;
    for (i = n; i > 0; i--) {
        product *= (i*1.0);
    }
    return product;
}

char getFactorialString(char **str, int len) {
    int i, j, carryOver, value;
    char buffer[3];
    
    // Initialize the string to have a length equal to the number of digits, and
    // let the string be equal to the value of 1 (set all string characters to
    // '0' except the last character which is set to '1')
    *str = (char *) malloc(len * sizeof(char));
    for (i = 0; i < len-1; i++)
        (*str)[i] = '0';
    (*str)[len-1] = '1';

    // For each number i up to and including the factorial number
    for (i = 1; i <= NUMBER; i++) {
        carryOver = 0;
        // We multiply it with each digit that makes up the overall value,
        // starting from the least significant digit to the most significant
        for (j = len-1; j >= 0; j--) {
            value = i * ((*str)[j]-'0') + carryOver;

            // We store the value in a buffer, which holds 3 digits 
            // (100 multiplied by a single-digit value returns a value with at
            // most 3 digits
            sprintf(buffer, "%03d", value);

            // We carry over the two significant digits for the next digit in
            // the string and update the current digit value
            carryOver = 10*(buffer[0]-'0') + (buffer[1]-'0');
            (*str)[j] = buffer[2];
        }
    }
}
