/*
Given a matrix which represents 1/0 representing a direct flight between two places in a 2D array, find the number of hops required to reach from one place to another place. In other words, find if it is bi-hop, tri-hop etc.
*/

#include<stdio.h>

#define N 4
#define MAX 999

int matrix[N][N] = {{0,1,0,0},
					{0,0,1,0},
					{0,0,0,1},
					{1,0,0,0}};

int min(int a, int b) {
		return (a <= b) ? a : b;
}
int getHops(int i, int j) {
		if(i == j)
				return 0;
		if(matrix[i][j] == 1)
				return 1;
		int k, best = MAX, hop_ik, hop_kj;
		for(k=i+1 ; k<N ; k++) {
				if(k == i || k == j)
						continue;
				printf("%d, %d, %d\n", i,j,k);
				hop_ik = getHops(i,k);
				hop_kj = getHops(k,j);
				if(hop_ik && hop_kj)
						best = min(best, getHops(i,k) + getHops(k,j));
		}
		return best;
}

void main() {
		int i = 0, j = 2;
		printf("Hops : %d\n", getHops(i, j));
}
