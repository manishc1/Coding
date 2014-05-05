*
All subsets of a set
*/

# include <stdio.h>
# include <string.h>

#define N 3

void printSet(int* set, int n) {
		int i;
		printf("{");
		for(i=0 ; i<n ; i++)
				printf("%d,", set[i]);
		printf("}  ");
}

void printSubset(int* set, int start, int end, int* subset, int n) {
		if (start > end)
				return;
		int i;
		for(i=start ; i<=end ; i++) {
				subset[n] = set[i];
				printSet(subset, n+1);
				printSubset(set, i+1, end, subset, n+1);
		}
}

void main() {
		int set[N] = {1,2,3};
		int subset[N];
		printSubset(set, 0, N-1, subset, 0);
}
