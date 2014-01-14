/*
 * 2520 is the smallest number that can be divided by each of the numbers from 1
 * to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the
 * numbers from 1 to 20?
 */

#include <stdio.h>

int main() {
    int number = 20;
    int divisor = 20;
    while (divisor > 0) {
        if (number % divisor == 0)
            divisor--;
        else {
            divisor = 20;
            number += 20;
        }
    }
    printf("%d\n", number);
}
