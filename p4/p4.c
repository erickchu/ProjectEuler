/*
 * A palindrome number reads the same both ways. The largest palindrome made
 * from the product of two 2-digit numbers is 9009 = 91 x 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <stdio.h>
#include <string.h>

int main() {
    int largestFactor = 999;
    int num1 = largestFactor, num2 = largestFactor, product;
    
    char buffer[8];
    int beginIndex, endIndex;
    int palindromeCheck = 0, result = 0;

    while (1) {
        product = num1 * num2;
        beginIndex = 0;
        endIndex = sprintf(buffer, "%d", product) - 1;

        palindromeCheck = 1;
        while (beginIndex < endIndex && palindromeCheck == 1) {
            if (buffer[beginIndex] == buffer[endIndex])
                palindromeCheck = 1;
            else
                palindromeCheck = 0;
            beginIndex++;
            endIndex--;
        }

        if (palindromeCheck == 1 && product > result) {
            result = product;
        }
        
        num2--;
        if (num2 == 0) {
            num2 = largestFactor;
            num1--;
            if (num1 == 0)
                break;
        }
    }

    printf("The largest palindrome made from the product of two three-digit ");
    printf("numbers is %d.\n", result);
}
