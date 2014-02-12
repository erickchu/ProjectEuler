/*
 * We shall say that an n-digit number is pandigital if it makes use of all the 
 * digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 
 * through 5 pandigital.
 * 
 * The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing 
 * multiplicand, multiplier, and product is 1 through 9 pandigital.
 *
 * Find the sum of all products whose multiplicand/multiplier/product identity 
 * can be written as a 1 through 9 pandigital.
 *
 * HINT: Some products can be obtained in more than one way so be sure to only 
 * include it once in your sum.
 */

#include <stdio.h>
#include <string.h>

int main() {
    // products hold the products summed (assuming 16 unique products at most),
    // sum holds the sum of products, count holds the number of products summed,
    // m is the multiplicand, n is the multiplier, p is the product
    int products[16] = {0}, sum = 0, count = 0, m, n, p;

    /*
     * If we multiply two 2-digit numbers, the product is at most 4 digits
     * If we multiply two 3-digit numbers, the product is at least 5 digits
     * If the multiplicand is 5 digits, the product is at least 5 digits
     * None of the above are 1-9 pandigital (total digits don't add up to 9)
     * Thus, the multiplicand must be 3-4 digits and the multiplier is 1-2 digits
     */
    for (m = 100; m < 10000; m++) {
        for (n = 1; n < 100; n++) {
            p = m * n;
            if (numLen(m) + numLen(n) + numLen(p) > 9)
                break;
            // If the total digits add up to 9
            else if (numLen(m) + numLen(n) + numLen(p) == 9) {
                // Check if it's pandigital, return p if so and 0 otherwise
                int pd = pandigital(m, n, p);

                // If it is pandigital, check if the product is unique
                if (pd > 0) {
                    int i;
                    for (i = 0; i < count; i++)
                        if (products[i] == p)
                            pd = 0;

                    if (pd != 0)
                        products[count++] = pd;
                }
            }
        }
    }
    
    for (m = 0; m < count; m++)
        sum += products[m];

    printf("%d\n", sum);
}

int numLen(int n) {
    if (n < 0) return 0;
    if (n < 10) return 1;
    if (n < 100) return 2;
    if (n < 1000) return 3;
    if (n < 10000) return 4;
    if (n < 100000) return 5;
    if (n < 1000000) return 6;
    if (n < 10000000) return 7;
    if (n < 100000000) return 8;
    if (n < 1000000000) return 9;
    if (n >= 1000000000) return 10;
}

// Check if a, b, and c are 1 through 9 pandigital; the sum of the number of
// digits of a, b, and c should be checked beforehand (== 9)
int pandigital(int a, int b, int c) {
    char aStr[8], bStr[8], cStr[8];
    int aLen = sprintf(aStr, "%d", a);
    int bLen = sprintf(bStr, "%d", b);
    int cLen = sprintf(cStr, "%d", c);

    // Go through each number digit by digit, and mark each digit n if it's
    // shown up by using array (i.e. array[n] = 1). If array[n] is 1, digit has
    // already shown up and thus numbers are not 1 to 9 pandigital
    int i, n, array[10] = { 0 };
    for (i = 0; i < aLen; i++) {
        n = aStr[i] - '0';
        if (array[n] == 1) 
            return 0;
        else 
            array[n] = 1;
    }
    for (i = 0; i < bLen; i++) {
        n = bStr[i] - '0';
        if (array[n] == 1) 
            return 0;
        else 
            array[n] = 1;
    }
    for (i = 0; i < cLen; i++) {
        n = cStr[i] - '0';
        if (array[n] == 1) 
            return 0;
        else 
            array[n] = 1;
    }
    
    // If one of the digits marked is a 0, than numbers aren't 1 to 9 pandigital
    if (array[0] == 1)
        return 0;

    // Otherwise, numbers are 1 to 9 pandigital; return c
    return c;
}
