# include <stdio.h>
# include <limits.h>

int getCostOfGrouping(int* a, int at, int N, int taken, int K, int prev, int diff) {
		int sumDiff, t, nt;
		if (at == N) {
				if (taken == K)
						return diff;
				printf("a[%d]=%d, taken=%d, prev=%d, diff=%d\n", at, a[at], taken, prev, diff);
				printf("Returning Max %d\n", INT_MAX);
				return INT_MAX;
		}

		if (taken == K) {
				sumDiff = 0;
				while(at<N) {
						sumDiff = sumDiff + (a[at] - a[prev]);
						at++;
				}
				printf("a[%d]=%d, taken=%d, prev=%d, diff=%d\n", at, a[at], taken, prev, diff);
				printf("Returning Diff %d\n", sumDiff);
				return sumDiff;
		}

		// not taken
		sumDiff = 0;
		if (at > 0)
				sumDiff = diff + (at-prev+1)*(a[at] - a[at-1]);
		nt = getCostOfGrouping(a, at+1, N, taken, K, prev, sumDiff);

		t = diff + getCostOfGrouping(a, at+1, N, taken+1, K, at, 0);

		printf("a[%d]=%d, taken=%d, prev=%d, diff=%d\n", at, a[at], taken, prev, diff);
		printf("Returning Min %d\n",  (nt <= t) ? nt : t);
		return (nt <= t) ? nt : t;
}

void main() {
		int a[4] = {1,2,5,7}, N=2, K=1;
		int cost = getCostOfGrouping(a, 0, N, 0, K, -1, 0);
		printf("%d\n", cost);
}
