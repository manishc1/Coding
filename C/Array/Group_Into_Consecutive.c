/*
Divide a list of numbers into group of consecutive numbers but their original order should be preserved? 
e.g. 
8,2,4,7,1,0,3,6 

2,4,1,0,3 and 8,7,6 

obviously in shortest time and space.
*/

# include <stdio.h>
# include <stdlib.h>

# define MAX 100

void group(int* a, int n) {
		int i, hash[MAX], setNum[MAX], set=1, min, max;

		//memset(hash, -1, sizeof(hash));
		for (i=0 ;i<MAX ; i++)
				hash[i] = setNum[i] = -1;

		for (i=0; i<n; i++)
				hash[a[i]] = i;

		i = 0;
		min = max = a[0];
		setNum[0] = set;
		while(i < n) {
				if (hash[min-1] > -1) {
						setNum[hash[min-1]] = set;
						min = min - 1;
				} else if (hash[max+1] > -1) {
						setNum[hash[max+1]] = set;
						max = max + 1;
				} else {
						while(setNum[i] != -1)
								i++;
						if (i >= n)
								break;
						min = max = a[i];
						setNum[i] = ++set;
				}
		}

		for (i=0 ; i<10 ; i++)
				printf("%d, ", hash[i]);
		printf("\n");
		for(i=0 ; i<n ; i++)
				printf("%d, ", a[i]);
		printf("\n");
		for(i=0 ; i<n ; i++)
				printf("%d, ", setNum[i]);
		printf("\n\n");
}

void main() {
		int a[MAX] = {8,2,4,7,1,3,5,9}, n = 8;
		group(a, n);
}
