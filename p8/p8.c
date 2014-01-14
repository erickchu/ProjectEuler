/*
 * Find the greatest product of five consecutive digits in the 1000-digit
 * number. (See 'number.txt')
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *numberFile = "number.txt";
    FILE *fp = fopen(numberFile, "r");
    int consecutiveDigits[5]; 
    int i = 0, product = 0;

    // Read the file containing the number character by character
    char digit;
    do {
        digit = fgetc(fp);

        // If the first 5 digits aren't stored, store it
        if (i < 5) {
            consecutiveDigits[i] = digit - '0';
            i++;
        }
        // Otherwise, calculate the product of the previous 5 digits
        // "Shift" the array to drop the oldest digit and add the newest digit
        else {
            if (digit != '\n') {
                product = max(productOfIntArray(consecutiveDigits, 5), product);
                consecutiveDigits[0] = consecutiveDigits[1]; 
                consecutiveDigits[1] = consecutiveDigits[2];
                consecutiveDigits[2] = consecutiveDigits[3];
                consecutiveDigits[3] = consecutiveDigits[4];
                consecutiveDigits[4] = digit - '0';
            }
        }
    } while (digit != EOF);
    
    printf("%d\n", product);
    fclose(fp);
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

