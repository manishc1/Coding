/*
Given a unordered array of numbers, remove the fewest number of numbers to produce the longest ordered sequence. Print count of fewest numbers to be removed, and the remaining sequence. 
For example, if input is 1 2 3 4 5 6 7 8 9 10, no (zero) numbers are removed, and input is the longest sequence. 
If input is, 1 2 3 8 10 5 6 7 12 9 4 0, then fewest number of elements to be removed is 5 is the fewest number to be removed, and the longest sequence is 1 2 3 5 6 7 12.
*/

# include <stdio.h>
# include <limits.h>

int min(int x, int y) {
		return (x <= y) ? x : y;
}

int costOfOrdering(int* a, int n, int i, int prev) {
		int taken, nottaken;
		if(i == n)
				return 0;
		if(a[i] >= prev)
				taken = costOfOrdering(a, n, i+1, a[i]);
		else
				taken = INT_MAX;
		nottaken = 1 + costOfOrdering(a, n, i+1, prev);
		return min(taken, nottaken);
}

void main() {
		int a[12] = {1, 2, 3, 8, 10, 5, 6, 7, 12, 9, 10, 11}, n = 12, del;
		del = costOfOrdering(a, n, 0, INT_MIN);
		printf("%d\n", del);
}
