/*
 * A perfect number is a number for which the sum of its proper divisors is 
 * exactly equal to the number. For example, the sum of the proper divisors of 
 * 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 * A number n is called deficient if the sum of its proper divisors is less than 
 * n and it is called abundant if this sum exceeds n.
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest 
 * number that can be written as the sum of two abundant numbers is 24. By 
 * mathematical analysis, it can be shown that all integers greater than 28123 
 * can be written as the sum of two abundant numbers. However, this upper limit 
 * cannot be reduced any further by analysis even though it is known that the 
 * greatest number that cannot be expressed as the sum of two abundant numbers 
 * is less than this limit.
 * Find the sum of all the positive integers which cannot be written as the sum 
 * of two abundant numbers.
 */

#include <stdio.h>
#include <math.h>

#define LIMIT 28128

int main() {
    // Store abundant numbers in array
	int i, abundantNumTotal = 0, abundantNums[LIMIT] = {0};
	for (i = 1; i < LIMIT; i++) {
		if (d(i) > i) {
			abundantNums[abundantNumTotal] = i;
			abundantNumTotal++;
		}
	}
	
    // Set up an array of numbers up to the limit
    // The value at index n is 1 if it can be summed by two abundant numbers
	int j, numbers[LIMIT] = {0};
	for (i = 0; i < abundantNumTotal; i++) {
        for (j = i; j < abundantNumTotal; j++) {
            if (abundantNums[i] + abundantNums[j] < LIMIT)
			    numbers[abundantNums[i] + abundantNums[j]] = 1;
        }
	}
	
    // Sum up all the values that cannot be summed by two abundant numbers
    int overallSum = 0;
	for (i = LIMIT-1; i >= 0; i--) {
		if (numbers[i] == 0) 
			overallSum += i;
	}
	
	printf("%d\n", overallSum);
}

// From p21; d(n) returns the sum of the proper divisors of n
// When we have a perfect divisor, we add both the divisor and its dividend,
// hence maxDivisor should never be greater than sqrt(number)
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
