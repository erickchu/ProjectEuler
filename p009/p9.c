/*
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which
 * a^2 + b^2 = c^2
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

#include <stdio.h>

int main() {
    int a = 1, b = 1, c = 1000 - (a + b), product;
    while (1) {
        // If triplet is found
        if (a*a + b*b == c*c) {
            printf("%d,%d,%d\n", a,b,c);
            product = a * b * c;
            break;
        }
        // Otherwise, increment 'b' and adjust 'c' such that a + b + c = 1000
        // If 'b' is incremented to the point where the calculated 'c' would be
        // negative (e.g. b >= 1000-a), we reset 'b' and increment 'a'
        else {
            b++;
            if (b >= 1000-a) {
                b = 1;
                a++;
            }
            c = 1000 - (a + b);
        }
    }

    printf("%d\n", product);
}

