/*
 * Surprisingly there are only three numbers that can be written as the sum of
 * fourth powers of their digits:
 * 1634 = 1^4 + 6^4 + 3^4 + 4^4
 * 8208 = 8^4 + 2^4 + 0^4 + 8^4
 * 9474 = 9^4 + 4^4 + 7^4 + 4^4
 * As 1 = 1^4 is not a sum it is not included.
 * The sum of these numbers is 1634 + 8208 + 9474 = 19316.
 * Find the sum of all the numbers that can be written as the sum of fifth
 * powers of their digits.
 */

#include <stdio.h>
#include <stdlib.h>

#define POWER 5
#define BUFFER_LEN 16

long sumOfPowers(long num);

int main() {
    int i, valueLength = 1, sumLength;
    long maxValue, maxSum;

    // Find the highest number we need to look up to
    while (1) {
        // Get the max possible value given a number of digits (i.e. all 9's)
        char maxValueStr[valueLength], *ptr;
        for (i = 0; i < valueLength; i++)
            maxValueStr[i] = '9';
        maxValue = strtol(maxValueStr, &ptr, 10);
    
        // Get the sum of powers of this value (e.g. 999 -> sum = 9^5+9^5+9^5)
        // Find the length of the sum (how many digits make it up)
        char buffer[BUFFER_LEN];
        maxSum = sumOfPowers(maxValue);
        sumLength = sprintf(buffer, "%ld", maxSum);
    
        // If sumLength < valueLength, then we only need to look at numbers with
        // less digits than valueLength, as we wouldn't be able to generate a
        // sum as large as a value for any greater number
        if (sumLength < valueLength)
            break;
        else
            valueLength++;
    }

    // Get the number of values we are looking up (or the value looking up to)
    // (e.g. valueLength = 6 -> 6 digits -> numValues = 100000)
    char numValues[valueLength], *ptr;
    numValues[0] = '1';
    for (i = 1; i < valueLength; i++)
        numValues[i] = '0';
    maxValue = strtol(numValues, &ptr, 10);

    // Sum all the numbers up to maxValue whose sum of powers is equal to the
    // number itself
    int sum = 0;
    for (i = 0; i < maxValue; i++) {
        if (sumOfPowers(i) == i)
            sum += i;
    }

    printf("%d\n", sum);
}

long sumOfPowers(long num) {
    char buffer[BUFFER_LEN];
    int i, length;
    long sum = 0;

    length = sprintf(buffer, "%ld", num);
    for (i = 0; i < length; i++)
        sum += power(buffer[i] - '0');

    return sum;
}

// n^POWER
int power(int n) {
    int i, value = 1;
    for (i = 0; i < POWER; i++)
        value *= n;
    return value;
}
