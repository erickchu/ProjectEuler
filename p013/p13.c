/*
 * Work out the first ten digits of the sum of the following one-hundred
 * 50-digit numbers. (See 'numbers.txt')
 */

#include <stdio.h>
#include <stdlib.h>

#define SEPARATE_SUMS 5
#define NUMBERS 100
#define DIGITS 50

void initializeNumArray(char ***array, char *fileName);
void getSums(char ***array, long long **sums);
void adjustSums(long long **array);
long long power(int base, int exponent);
void printOverallSum(long long **array);
void printAnswer(long long **array);

int main() {
    char **number, *fileName = "numbers.txt";
    long long *sums;

    // See functions below for more information
    initializeNumArray(&number, fileName);
    getSums(&number, &sums);
    adjustSums(&sums);
    printAnswer(&sums);
}

// Initialize the array that holds all the numbers (in the form of strings)
// Use fscanf to read each number in (numbers are line-by-line in file)
void initializeNumArray(char ***array, char *fileName) {
    int i;
    FILE *fp = fopen(fileName, "r");
    *array = (char **) malloc(NUMBERS * sizeof(char *));
    for (i = 0; i < NUMBERS; i++) {
        (*array)[i] = (char *) malloc((DIGITS + 1) * sizeof(char));
        fscanf(fp, "%s", (*array)[i]);
    }
    fclose(fp);
}

// Since the numbers are too long, we break up each number into five 10-digit
// numbers and store five separate sums of all the numbers
void getSums(char ***array, long long **sums) {
    *sums = (long long *) malloc(SEPARATE_SUMS * sizeof(long long));
    
    // Get the sum of the last ten digits of all the numbers, store in sums[4],
    // then the next ten digits of all the numbers, store in sums[3], etc.
    int i, j, k; 
    long long tenDigitValue;
    for (i = DIGITS-1; i >= 0; i -= 10) {
        (*sums)[i/10] = 0;
        for (j = 0; j < NUMBERS; j++) {
            k = i;
            tenDigitValue = 0;
            while (k > i-10) {
                tenDigitValue += ((*array)[j][k] - '0') * power(10, 9-(k%10));
                k--;
            }

            // By the end,
            // sums[4] will store the sum of all numbers' last 10 digit values
            // sums[0] will store the sum of all numbers' first 10 digit values
            (*sums)[i/10] += tenDigitValue;
        }
    }
}

// The sums formed from getSums are ~12 digit values (100 * 10-digit values)
// Carry over the greater significant numbers from the "lesser" sums to the
// "greater" sums
void adjustSums(long long **array) {
    char buffer[12]; 
    int carryOver = 0, i;
    for (i = 4; i >= 0; i--) {
        (*array)[i] = (*array)[i] + carryOver;
        sprintf(buffer, "%lld", (*array)[i]);
        // Only the front two digits are carried over
        carryOver = 10 * (buffer[0] - '0') + (buffer[1] - '0');
    }
}

// Returns base^exponent
long long power(int base, int exponent) {
    int i, value = 1;
    for (i = 0; i < exponent; i++) {
        value *= base;
    }
    return value;
}

void printOverallSum(long long **array) {
    int i;
    for (i = 0; i < SEPARATE_SUMS; i++) {
        printf("%lld", (*array)[i]);
    }
    printf("\n");
}

void printAnswer(long long **array) {
    int i;
    char buffer[12];
    sprintf(buffer, "%lld", (*array)[0]);
    for (i = 0; i < 10; i++) {
        printf("%c", buffer[i]);
    }
    printf("\n");
}
