/*
 * Starting with the number 1 and moving to the right in a clockwise direction a
 * 5 by 5 spiral is formed as follows:
 *
 * 21 22 23 24 25
 * 20  7  8  9 10
 * 19  6  1  2 11
 * 18  5  4  3 12
 * 17 16 15 14 13
 *
 * It can be verified that the sum of the numbers on the diagonals is 101.
 * What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral 
 * formed in the same way?
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 1001


int main() {
	int i, sum = 0;

    // Let x represent row, y represent column in the spiral "array"
    // Let n represent the spiral "count" (increases as we get further out)
    int x = SIZE/2 + 1, y = SIZE/2 + 1, n = 0;

    // Let c == 1 when x, y is at the corner of a spiral
    // Let down, left, up, and right represent the number of steps we have left
    // to iterate through the current spiral (we go from down->left->up->right)
    int c = 1, down = 0, left = 0, up = 0, right = 1;

    // Follow a spiral path; incrementing the value 'i' with each step taken
	for (i = 1; i <= SIZE*SIZE; i++) {
        // If 'i' is a corner value of the spiral, add it to the sum as the
        // corners of each spiral make up the diagonal
        if (c == 1) 
            sum += i;

		if (down > 0) {
			x++; // Move to the next row
            if (--down == 0)    c = 1;
            else                c = 0;
        }
		else if (left > 0) {
			y--; // Move to the previous column
            if (--left == 0)    c = 1;
            else                c = 0;
        }
		else if (up > 0) {
			x--; // Move to the previous row
            if (--up == 0)      c = 1;
            else                c = 0;
        }
		else if (right > 0) {
			y++; // Move to the next column
            if (--right == 1)   c = 1;
            else                c = 0;

            // When right = 0, we move into the next spiral, so we refresh the
            // D/L/U/R values (which depend on the spiral count)
            if (right == 0) {
                n++;
			    down = 2*n - 1;
		    	left = 2*n;
			    up = 2*n;
			    right = 2*n + 1;			
		    }
        }
    }

    printf("%d\n", sum);
}
