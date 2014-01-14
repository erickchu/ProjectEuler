/*
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five,
 * then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out
 * in words, how many letters would be used?
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and
 * forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20
 * letters. The use of "and" when writing out numbers is in compliance with
 * British usage.
 */

#include <stdio.h>

#define NUMBERS 1000
#define THOUSAND_LEN 8
#define HUNDRED_LEN 7
#define AND_LEN 3

int main() {
    int i, sum = 0, numValue, numLetters;
    for (i = 1; i <= NUMBERS; i++) {
        numValue = i;
        numLetters = 0;

        // Get the number of letters of the number's "thousands" value
        if (numValue >= 1000) {
            numLetters += singleDigitLength(numValue / 1000) + THOUSAND_LEN;
            numValue %= 1000;
        }

        // Get the number of letters of the number's "hundreds" value
        if (numValue >= 100) {
            numLetters += singleDigitLength(numValue / 100) + HUNDRED_LEN;
            numValue %= 100;
        }

        // If there is a remainder from dividing the value by 100 and the
        // original value is over 100, then include the length of "and"
        if (i >= 100 && numValue != 0)
            numLetters += AND_LEN;

        // If the remainder value is greater than 20
        if (numValue >= 20) {
            int onesPlace = 0;
            while (numValue % 10 != 0) {
                numValue--;
                onesPlace++;
            }
            numLetters += divisibleByTenLength(numValue) + singleDigitLength(onesPlace);
        }
        // Else if the value is between 10 and 20
        else if (numValue > 10) {
            numLetters += teenLength(numValue);
        }
        // Else value is either ten or a single-digit value (or zero)
        else {
            numLetters += singleDigitLength(numValue);
        }

        sum += numLetters;
    }

    printf("%d\n", sum);
}

int singleDigitLength(int num) {
    switch(num) {
    case 1: return 3; // one
    case 2: return 3; // two
    case 3: return 5; // three
    case 4: return 4; // four
    case 5: return 4; // five
    case 6: return 3; // six
    case 7: return 5; // seven
    case 8: return 5; // eight
    case 9: return 4; // nine
    case 10: return 3; // ten
    default: return 0;
    }
}

int divisibleByTenLength(int num) {
    switch(num) {
    case 10: return 3; // ten
    case 20: return 6; // twenty
    case 30: return 6; // thirty
    case 40: return 5; // forty
    case 50: return 5; // fifty
    case 60: return 5; // sixty
    case 70: return 7; // seventy
    case 80: return 6; // eighty
    case 90: return 6; // ninety
    default: return 0;
    }
}

int teenLength(int num) {
    switch(num) {
    case 11: return 6; // eleven
    case 12: return 6; // twelve
    case 13: return 8; // thirteen
    case 14: return 8; // fourteen
    case 15: return 7; // fifteen
    case 16: return 7; // sixteen
    case 17: return 9; // seventeen
    case 18: return 8; // eighteen
    case 19: return 8; // nineteen
    default: return 0;
    }
}
