/* Find connected 1s */

#include <stdio.h>

int max(int x, int y) {
		return (x>y?x:y);
}

int find1(int a[][4], int i, int j, int flag) {
		if(i>=4 || j>=4)
				return 0;
		if((a[i][j] == 0) && (flag == 1))
				return 0;
		if((a[i][j] == 0) && (flag == 0))
				return max(find1(a,i+1,j,0),find1(a,i,j+1,0));
		if(a[i][j] == 1)
				return 1 + max(find1(a,i+1,j,1),find1(a,i,j+1,1));
}

void main() {
		int a[4][4] = {{0,0,1,1},{1,1,1,0},{1,0,1,0},{0,1,0,1}};
		printf("%d\n",find1(a, 0, 0, 0));
}
