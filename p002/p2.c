/*
 * Each new term in the Fibonacci sequence is generated by adding the previous
 * two terms. By starting with 1 and 2, the first 10 terms will be:
 * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 * By considering the terms in the Fibonacci sequence whose values do not exceed
 * four million, find the sum of the even-valued terms.
 */

#include <stdio.h>

int main() {
    int prev = 1, prev2 = 2, current, sum = 0;
    sum = 2;

    while (prev2 < 4000000) {
        current = prev + prev2;
        if (current % 2 == 0)
            sum += current;
        prev = prev2;
        prev2 = current;
    }

    printf("%d\n", sum);
}