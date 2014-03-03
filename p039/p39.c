/*
 * If p is the perimeter of a right angle triangle with integral length sides,
 * {a,b,c}, there are exactly three solutions for p = 120.
 * {20,48,52}, {24,45,51}, {30,40,50}
 */

#include <stdio.h>

#define LIMIT 1000

int main() {
    int a, b, c, p, count, maxP, maxCount = 0;
    for (p = 3; p <= LIMIT; p++) {
        count = 0;
        for (a = 1; a < p - 1; a++) {
            for (b = a; b < p - 1; b++) {
                if (a + b > p)
                    break;
                else {
                    c = p - a - b;
                    if (a*a + b*b == c*c)
                        count++;
                }
            }
        }

        if (count > maxCount) {
            maxCount = count;
            maxP = p;
        }
    }

    printf("%d (%d)\n", maxP, maxCount);
}

