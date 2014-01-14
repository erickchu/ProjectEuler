/*
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
 * that the 10001th prime is 13.
 * What is the 10,001st prime number?
 */

#include <stdio.h>

int main() {
    // Count the first prime number (2) by default, hence primeNo = 1 and we
    // start with number = 3
    int i, maxPrimeNo = 100001, primeNo = 1, number = 3, checkPrime = 0;
    
    while (primeNo < maxPrimeNo) {
        checkPrime = 1;
        for (i = number-1; i > 1; i--) {
            if (number % i == 0)
                checkPrime = 0;
        }
        if (checkPrime == 1) {
            primeNo++;
            if (primeNo == maxPrimeNo)
                break;
        }
        number += 2; // Prime numbers after 2 are odd
    }

    printf("%d\n", number);
}
