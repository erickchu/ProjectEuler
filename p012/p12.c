/*
 * The sequence of triangle numbers is generated by adding the natural numbers.
 * So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first
 * ten terms would be:
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 * Let us list the factors of the first seven triangle numbers:
 * 1: 1
 * 3: 1, 3
 * 6: 1, 2, 3, 6
 * 10: 1, 2, 5, 10
 * 15: 1, 3, 5, 15
 * 21: 1, 3, 7, 21
 * 28: 1, 2, 4, 7, 14, 28
 * We can see that 28 is the first triangle number to have over five divisors.
 * What is the value of the first triangle number to have over five hundred
 * divisors?
 */

#include <stdio.h>

#define DIVISOR_NUM 500

int main() {
    int i = 1, j, divisorCount, maxDivisor;
    long long int triangleNum = 0;
    while (1) {
        // Generate the new triangle number
        triangleNum += i;
        
        j = 1;
        divisorCount = 0;
        maxDivisor = triangleNum;
        while (j <= maxDivisor) {
            // If we found a divisor 'j', we can increment the divisorCount by 2
            // as the diviend is also a divisor (special case occurs if the
            // divisor and diviend are the same, in which increment by 1)
            if (triangleNum % j == 0) {
                if (triangleNum / j == j) 
                    divisorCount++;
                else
                    divisorCount += 2;
                maxDivisor = triangleNum / j;
            }
            j++;
        }
        
        // If the triangle number has over DIVISOR_NUM divisors, break
        if (divisorCount > DIVISOR_NUM)
            break;

        i++;
    }

    printf("%lld\n", triangleNum);
}
