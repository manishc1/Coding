# include <stdio.h>

int ways = 0;

void countways(int n) {
		if (n < 2) {
				ways++;
				return;
		}
		countways(n-1);
		countways(n-2);
}

void main() {
		int n;
		printf("n : ");
		scanf("%d", &n);
		countways(n);
		printf("Ways : %d\n", ways);
}
