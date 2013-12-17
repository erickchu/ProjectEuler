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

    printf("The sum of the even-valued terms in the Fibonacci sequence ");
    printf("up to 4000000 is %d.\n", sum);
}
