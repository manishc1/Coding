/*
Write a method which finds the maximum of two numbers. You should not use if-else
or any other comparison operator.

EXAMPLE
Input: 5, 10
Output: 10
		
SOLUTION
Let’s try to solve this by “re-wording” the problem. We will re-word the problem until we get
something that has removed all if statements.
Rewording 1: If a > b, return a; else, return b.
Rewording 2: If (a - b) is negative, return b; else, return a.
Rewording 3: If (a - b) is negative, let k = 1; else, let k = 0. Return a - k * (a - b).
Rewording 4: Let c = a - b. Let k = the most significant bit of c. Return a - k * c.
We have now reworded the problem into something that fits the requirements. The code
for this is below.
*/

# include <stdio.h>

int getMax(int a, int b) {
		int diff = a - b;
		int sign = (diff >> (8*sizeof(int)-1)) & 0x1;
		//int sign = (diff << 1);
		int max = a - sign * diff;
		return max;
}

void main() {
		printf("%d\n",getMax(1,2));
}
