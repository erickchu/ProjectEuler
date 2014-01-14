/*
 * The sum of the squares of the first ten natural numbers is,
 * 1^2 + 2^2 + ... + 10^2 = 385
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)^2 = 55^2 = 3025
 * Hence the difference between the sum of the squares of the first ten natural
 * numbers and the square of the sum is 3025 - 385 = 2640.
 * Find the difference between the sum of the squares of the first hundred
 * natural numbers and the square of the sum.
 */

#include <stdio.h>

int main() {
    int numOfNaturalNumbers = 100;
    int sumOfSquares = 0, squareOfSums = 0, difference;
    
    int i;
    for (i = 1; i <= numOfNaturalNumbers; i++) {
        sumOfSquares += i * i;
        squareOfSums += i;
    }
    squareOfSums = squareOfSums * squareOfSums;
    difference = squareOfSums - sumOfSquares;
    printf("%d\n", difference);
}
