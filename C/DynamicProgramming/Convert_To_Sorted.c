/*
Given an array A of positive integers. Convert it to a sorted array with minimum cost. The only valid operation are: 
1) Decrement with cost = 1 
2) Delete an element completely from the array with cost = value of element
*/

# include <stdio.h>

int sort(int* a, int n, int i) {
		int decCost, dec, delCost, nextCost;
		if (i == n-1)
				return 0;
		nextCost = sort(a, n, i+1);
		dec = a[i] - a[i+1];
		delCost = nextCost + a[i];
		decCost = nextCost + dec;

		if (delCost < decCost) {
				a[i] = -1;
				return delCost;
		}
		a[i] = dec;
		return decCost;
}

void main() {
		int i, n = 3, a[5] = {2,2,1}, cost;
		cost = sort(a, n, 0);
		printf("%d\n", cost);
		for(i=0; i<n; i++)
				printf("%d ", a[i]);
}
