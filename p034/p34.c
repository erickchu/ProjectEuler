/*
 * 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 * Find the sum of all numbers which are equal to the sum of the factorial of
 * their digits.
 * Note: as 1! = 1 and 2! = 2 are not sums they are not included.
 */

#include <stdio.h>

long sumOfFactorials(long num);

int main() {
    /* Similar to problem 30 but using factorials as opposed to powers
     * Figure out the largest number we need to look up to, then look at each
     * number up until that number (see problem 30 for details)
     */
    int i, valueLength = 1, sumLength;
    long maxValue, maxSum;

    while (1) {
        char maxValueStr[valueLength], *ptr;
        for (i = 0; i < valueLength; i++)
            maxValueStr[i] = '9';
        maxValue = strtol(maxValueStr, &ptr, 10);
    
        char buffer[16];
        maxSum = sumOfFactorials(maxValue);
        sumLength = sprintf(buffer, "%ld", maxSum);

        if (sumLength < valueLength)
            break;
        else
            valueLength++;
    }

    char numValues[valueLength], *ptr;
    numValues[0] = '1';
    for (i = 1; i < valueLength; i++)
        numValues[i] = '0';
    maxValue = strtol(numValues, &ptr, 10);

    int sum = 0;
    for (i = 3; i < maxValue; i++) {
        if (sumOfFactorials(i) == i)
            sum += i;
    }

    printf("%d\n", sum);
}

long sumOfFactorials(long num) {
    char buffer[16];
    int i, length;
    long sum = 0;

    length = sprintf(buffer, "%ld", num);
    for (i = 0; i < length; i++)
        sum += factorial(buffer[i] - '0');

    return sum;
}

int factorial(int n) {
    if (n <= 0)
        return 1;

    int i, result = 1;
    for (i = 1; i <= n; i++)
        result *= i;
    
    return result;
}
