/*
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143?
 */

#include <stdio.h>

int main() {
    int primeFactor = 2;
    long long int number = 600851475143;
    while (number > primeFactor) {
        if (number % primeFactor == 0) {
            number = number / primeFactor;
        }
        primeFactor++;
    }

    printf("%d\n", primeFactor);
}
