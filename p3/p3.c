/*
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143?
 */

#include <stdio.h>

int main() {
    int i = 2;
    long long int number = 600851475143;
    
    long long int value = number;
    while (value > i) {
        if (value % i == 0) {
//            printf("%d,", i);
            value = value / i;
        }
        i++;
    }

    printf("The largest prime factor of %lld is %d.\n", number, i);
}
