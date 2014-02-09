/*
Matrix
0 1 2
3 4 5
6 7 8

Print
0
3 1
6 4 2
7 5
8
*/

# include <stdio.h>

int min (int x, int y)
{
	if (x >= y)
		return y;
	return x;
}

int max (int x, int y)
{
	if (x >= y)
		return x;
	return y;
}

void main()
{
		int a[4][3] = {{0,1,2},
					   {3,4,5},
					   {6,7,8},
					   {9,10,11}};
	int i, j, k, m = 4, n = 3;

	for (k = 0 ; k < m+n-1 ; k++)
	{
			for (i = min(k,(m-1)), j = max(0,k-(m-1)) ; i >= max(0,k-n-1) && j <= min(k,n-1) ; i-- , j++)
				printf("%d(%d,%d) ", a[i][j],i,j);
		printf("\n");
	}
}
