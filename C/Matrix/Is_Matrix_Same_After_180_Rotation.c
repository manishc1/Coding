# include <stdio.h>

void main() {
		int a[3][5] = {{1,2,1,0,9},
					   {5,6,7,6,5},
		               {9,0,1,2,1}};
		int N = 3, M = 5;
		int i,j,k;
		int flag = 0;
		j = 0;
		for(i=0 ; i<N ; i++) {
				j += i*(M/N);				
				for (k=0 ; k<=j ; k++) {
						if(a[i][k] != a[N-i-1][M-k-1]) {
								flag = 1;
								break;
						}
				}
				if (flag)
						break;
		}
		if (flag)
				printf("No\n");
		else
				printf("Yes\n");
}
