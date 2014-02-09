/*
Time = O(M * N)
N = number of items
M = Capacity of Knapsack

Space O(M)
*/

# include <stdio.h>

#define N 4

int max(int x, int y) {
		return (x>y) ? x : y;
}
void memoized_unbounded_knapsack(int* W, int* V, int M) {
		int K[M+1];
		int i, w;
		int WLen = N, best;
		K[0] = 0;

		for(w=1 ; w<=M ; w++) {
				best = 0;
				for(i=0 ; i<WLen ; i++) {
						if(W[i] <= w) {
								best = max(best, K[w-W[i]]+V[i]);
						}
				}
				K[w] = best;
		}

		printf("DAG : ");
		for(i=0 ; i<=M ; i++) {
				printf(" %d ", K[i]);
		}
		printf("\n");
}

int unmemoized_unbounded_knapsack(int* W, int* V, int m) {
		int i, best;
		if(m <= 0)
				return 0;
		best = 0;
		for(i=0 ; i<N ; i++) {
				if(W[i] <= m)
						best = max(best, V[i] + unmemoized_unbounded_knapsack(W, V, m-W[i]));
		}
		return best;
}

void main() {
		int W[N] = {6,3,4,2};
		int V[N] = {30,14,16,9};
		int M = 10;
		memoized_unbounded_knapsack(W, V, M);
		printf("\n%d\n", unmemoized_unbounded_knapsack(W, V, M));
}
