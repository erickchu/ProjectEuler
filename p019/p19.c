/*
 * You are given the following information, but you may prefer to do some
 * research yourself.
 * 1 Jan 1900 was a Monday.
 * Thirty days has September, April, June, and November. All the rest have
 * thirty-one, saving February alone, which has twenty-eight, rain or shine. And
 * on leap years, twenty-nine.
 * A leap year occurs on any year evenly divisible by 4, but not on a century
 * unless it is divisible by 400.
 * How many Sundays fell on the first of the month during the twentieth century
 * (1 Jan 1901 to 31 Dec 2000)?
 */

#include <stdio.h>

void incrementMonth(int *month, int *year, int *leapYear, int *daysInMonth);

int main() {
    // If Jan 1 1900 was a Mon, Jan 7 1900 is a Sunday
    // 1900 is not a leap year, 31 days in January
    int month = 1, day = 7, year = 1900;
    int leapYear = 0, daysInMonth = 31, firstSundayCounter = 0;

    while ( year <= 2000 ) {
        day += 7;
        if (day > daysInMonth) {
            day = day - daysInMonth;
            incrementMonth(&month, &year, &leapYear, &daysInMonth);
            if (day == 1 && year > 1900)
                firstSundayCounter++;
        }
    }
    printf("%d\n", firstSundayCounter);
}

int getLeapYear(int year) {
    if ( (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0) )
        return 1;
    else
        return 0;
}

int getDaysInMonth(int month, int leapYear) {
    if (month == 2) {
        if (leapYear == 0)
            return 28;
        else
            return 29;
    }
    else if (month == 9 || month == 4 || month == 6 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}


void incrementMonth(int *month, int *year, int *leapYear, int *daysInMonth) {
    *month += 1;
    if (*month > 12) {
        *year += 1;
        *month = 1;
        *leapYear = getLeapYear(*year);
    }
    *daysInMonth = getDaysInMonth(*month, *leapYear);
}
