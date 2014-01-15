/*
 * The following iterative sequence is defined for the set of positive integers:
 * n -> n/2 (n is even)
 * n -> 3n + 1 (n is odd)
 * Using the rule above and starting with 13, we generate the following
 * sequence:
 * 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 * It can be seen that this sequence (starting at 13 and finishing at 1)
 * contains 10 terms. Although it has not been proved yet (Collatz Problem), it
 * is thought that all starting numbers finish at 1.
 * Which starting number, under one million, produces the longest chain?
 */

#include <stdio.h>

#define NUMBERS 1000000

unsigned long nextTermInSeq(unsigned long n);

int main() {
    int longestChain = 1, answer = 1;
    int i, currentChain;
    unsigned long currentNum; // ints are not large enough to store certain
                              // terms in some sequences
    for (i = 1; i < NUMBERS; i++) {
        currentNum = i;
        currentChain = 1;
        while ( currentNum > 1 ) {
            currentNum = nextTermInSeq(currentNum);
            currentChain++;
        }
        if (currentChain > longestChain) {
            answer = i;
            longestChain = currentChain;
        }
    }
    printf("%d (%d)\n", answer, longestChain);
}

unsigned long nextTermInSeq(unsigned long n) {
    if (n % 2 == 0) 
        return n/2;
    else 
        return 3*n + 1;
}
