/* The number, 197, is called a circular prime because all rotations of the 
 * digits: 197, 971, and 719, are themselves prime.
 *
 * There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71,
 * 73, 79, and 97.
 *
 * How many circular primes are there below one million?
 */
 
#include <stdio.h>
#include <stdlib.h>

#define PRIMES_BELOW 1000000

int main() {
    // primes hold the primes below 1000000, count holds the number of primes
    // checkPrimes hold 'P' at index i if value i is prime, 'N' otherwise
	int p = 0, primes[PRIMES_BELOW], count = 0;
    char checkPrimes[PRIMES_BELOW] = "";
    
    // Sieve of Erathosthenes; collect the primes
    while (p < PRIMES_BELOW) {
        if (p == 0 || p == 1)
            checkPrimes[p] = 'N';
        else if (checkPrimes[p] == 0) {
			checkPrimes[p] = 'P';
            primes[count] = p;
			count++;
            int multiple = p * 2;
            while (multiple < PRIMES_BELOW) {
                checkPrimes[multiple] = 'N';
                multiple += p;
            }
        }
        p++;
    }

    // Get circular primes
    int circularPrimes = 0;
    for (p = 0; p < count; p++)
        circularPrimes += checkCircularPrime(primes[p], checkPrimes);

    printf("%d\n", circularPrimes);
}

int getLength(int num) {
    if (num < 0) return 0;
    if (num < 10) return 1;
    if (num < 100) return 2;
    if (num < 1000) return 3;
    if (num < 10000) return 4;
    if (num < 100000) return 5;
    if (num < 1000000) return 6;
    else return 7;
}

int checkCircularPrime(int num, char array[]) {
    int i, j, circular = 1, numLen = getLength(num);
    char numberStr[6], temp;
    
    // The number of rotations depends on the length of the number
    for (i = 0; i < numLen; i++) {
        // If num isn't prime, than the original value isn't a circular prime
        if (array[num] != 'P') {
            circular = 0;
            break;
        }
        // If num is prime, "rotate" the digits and check the next value
        else {
            sprintf(numberStr, "%d", num);
            temp = numberStr[numLen - 1];
            for (j = numLen-1; j > 0; j--)
                numberStr[j] = numberStr[j-1];
            numberStr[0] = temp;
            num = atoi(numberStr);
        }
    }

    return circular;
}
