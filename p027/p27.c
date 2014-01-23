/*
 * Euler discovered the remarkable quadratic formula:
 * n^2 + n + 41
 *
 * It turns out that the formula will produce 40 primes for the consecutive
 * values n = 0 to 39. However, when n = 40, 40^2 + 40 +41 = 40(40 + 1) + 41 is
 * divisible by 41, and certainly when n = 41, 41^2 + 41 + 41 is clearly
 * divisible by 41.
 *
 * The incredible formula n^2 - 79n + 1601 was discovered, which produces 80
 * primes for the consecutive values n = 0 to 79. The product of the
 * coefficients, -79 and 1601, is -126479.
 *
 * Considering quadratics of the form:
 * n^2 + an + b, where |a| < 1000 and |b| < 1000 
 * (where |n| is the modulus/absolute value of n)
 * Find the product of the coefficients, a and b, for the quadratic expression
 * that produces the maximum number of primes for consecutive values of n,
 * starting with n = 0.
 */

#include <stdio.h>
#include <stdlib.h>

#define COEFFICIENT_LIMIT 1000

void getPrimesBelowLimit(int **primes, int *numPrimes);
long evaluateFormula(int n, int a, int b);

int main() {
    // Get all the primes below the coefficient limit (1000)
    int numPrimes = 0, *primes;
    getPrimesBelowLimit(&primes, &numPrimes);

    int a, b, i, j, n;
    int maxN = 0, coeffA, coeffB;

    // For each possible 'a' value (from -999 to 999)
    for (a = -1*COEFFICIENT_LIMIT + 1; a < COEFFICIENT_LIMIT; a++) {

        // For each possible 'b' value (prime numbers between -1000 and 1000)
        // 'b' has to be a prime number 'p'; when n = 0, (0*0 + 0*a + b = p)
        for (i = 0; i < numPrimes; i++) {
            for (j = -1; j < 2; j += 2) {
                b = j * primes[i];
                
                // Start at n = 0, continue to evaluate formula for increasing n
                // until the returned result is not prime
                n = 0;
                while ( checkIfPrime(evaluateFormula(n, a, b)) != 0 )
                    n++;

                // Update the maximum number of consecutive primes
                if (n > maxN) {
                    maxN = n;
                    coeffA = a;
                    coeffB = b;
                }
            }
        }
    }

    printf("%d consecutive values of n (a=%d, b=%d)\n", maxN, coeffA, coeffB);
    printf("%d*%d = %d\n", coeffA, coeffB, coeffA*coeffB);
}

// Get the primes below the limit (i.e. 1000) and store it in primes array
void getPrimesBelowLimit(int **primes, int *numPrimes) {
    // Sieve of Erathosthenes
    int pMultiple, p = 2, numbers[COEFFICIENT_LIMIT] = {0};
    numbers[0] = 1;
    numbers[1] = 1;
    while (p < COEFFICIENT_LIMIT) {
        if (numbers[p] == 0) {
            (*numPrimes)++;
            pMultiple = p + p;
            while (pMultiple < COEFFICIENT_LIMIT) {
                numbers[pMultiple] = 1;
                pMultiple += p;
            }
        }
        p++;
    }

    // Put all the prime values into the array
    *primes = (int *) malloc(*numPrimes * sizeof(int));
    int i = 0;
    for (p = 2; p < COEFFICIENT_LIMIT; p++) {
        if (numbers[p] == 0) {
            (*primes)[i] = p;
            i++;
        }
    }
}

// Evaluate the formula n^2+an+b
long evaluateFormula(int n, int a, int b) {
    return (n*n + a*n + b);
}

// Returns 1 if n is prime, returns 0 otherwise
int checkIfPrime(long n) {
    int i;
    if (n < 0) {
        for (i = -2; i > n; i--)
            if (n % i == 0)
                return 0;
    }
    else {
        for (i = 2; i < n; i++) {
            if (n % i == 0)
                return 0;
        }
    }
    return 1;
}
