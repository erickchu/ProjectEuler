/*
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 */

#include <stdio.h>

#define PRIMES_BELOW 2000000

int main() {
    int p = 2;
    long long int sum = 0;
    char number[PRIMES_BELOW] = "";
    number[0] = 1;
    number[1] = 1;
    
    // Sieve of Erathosthenes
    while (p < PRIMES_BELOW) {
        if (number[p] == 0) {
            sum += p;
            int multiple = p;
            while (multiple < PRIMES_BELOW) {
                number[multiple] = 1;
                multiple += p;
            }
        }
        p++;
    }

    printf("%lld\n", sum);
}

