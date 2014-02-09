# include <stdio.h>

int getLongestConsecIntegers(int *a, int n) {
		int max = 0, i, len = 1;

		if (n == 0)
				return 0;

		for (i=1 ; i<n ; i++) {
				if (a[i-1] + 1 == a[i])
						len ++;
				else {
						if (len > max)
								max = len;
						len = 1;						
				}
		}
		if (len > max)
				return len;
		return max;
}

void main() {
		int a[12] = {1,2,3,4,5,1,2,3,4,5,6,7};
		printf("%d\n", getLongestConsecIntegers(a, 12));
}
