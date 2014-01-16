/*
 * Let d(n) be defined as the sum of proper divisors of n (numberbers less than n
 * which divide evenly into n).
 * If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and
 * each of a and b are called amicable numberbers.
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44,
 * 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4,
 * 71, and 142; so d(284) = 220.
 */

#include <stdio.h>
#include <math.h>

#define LIMIT 10000

int d(int number);

int main() {
    int i, possiblePair;
    int sum = 0;
    int numbers[LIMIT+1] = { 0 };

    for (i = 1; i <= LIMIT; i++) {
        if (numbers[i] == 0) {
            possiblePair = d(i);
            if (d(possiblePair) == i && possiblePair != i) {
                sum += possiblePair + i;
                numbers[possiblePair] = i;
            }
        }
        numbers[i] = 1;
    }

    printf("%d\n", sum);
}

int d(int number) {
    int divisor = 1, dividend, maxDivisor = sqrt(number)+1, sum = 0;
    while (divisor < maxDivisor) {
        if (number % divisor == 0) {
            dividend = number / divisor;
            sum += divisor;
            if (divisor != 1 && divisor != dividend) 
                sum += dividend;
        }
        divisor++;
    }
    return sum;
}

