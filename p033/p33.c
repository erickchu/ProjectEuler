/*
 * The fraction 49/98 is a curious fraction, as an inexperienced mathematician 
 * in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which 
 * is correct, is obtained by cancelling the 9s.
 *
 * We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
 *
 * There are exactly four non-trivial examples of this type of fraction, less 
 * than one in value, and containing two digits in the numerator and
 * denominator.
 *
 * If the product of these four fractions is given in its lowest common terms, 
 * find the value of the denominator.
 */

#include <stdio.h>

int main() {
    int n1, d1, n2, d2;
    double result, simplified;
    char numerator[2], denominator[2];
    int productNum = 1, productDenom = 1;
    
    for (n1 = 10; n1 < 99; n1++) {
        for (d1 = n1+1; d1 < 100; d1++) {
            sprintf(numerator, "%d", n1);
            sprintf(denominator, "%d", d1);
            if (numerator[1] == denominator[0]) {
                n2 = numerator[0] - '0';
                d2 = denominator[1] - '0';
                result = (n1 * 1.0) / (d1 * 1.0);
                simplified = (n2 * 1.0) / (d2 * 1.0);
                if (result == simplified) {
                    productNum *= n2;
                    productDenom *= d2;
                }
            }
        }
    }

    for (n1 = productNum; n1 > 0; n1--) {
        if (productNum % n1 == 0 && productDenom % n1 == 0) {
            printf("%d\n", productDenom / n1);
            break;
        }
    }
}

