/*
You are given a squared integer matrix of nxn size in which all rows and all columns 
are sorted in ascending order. The task is to check if the given matrix contains a given key.
*/

# include <stdio.h>

void search (int a[][4], int n, int key, int *row, int *col) {
	int k,l=0,m,u=n-1,r,c;
	printf("\nDiag");
	while(l<u) {
		m = (l+u)/2;
		printf("\n%d,  %d,%d,%d",a[m][m],l,m,u);
		if (a[m][m] == key) {
			*row = m; *col = m;
			return;
		}
		if ((l+1==u) && (key<a[l][l]) && (a[u][u]>key))
			break;
		if (key < a[m][m]) {
			if (m == u)
				break;
			u = m;
		}
		else if (a[m][m] < key) {
			if (m == l)
				break;
			l = m;
		}
	}
	
	r = u; c = u;
printf("\nRow : %d",a[u][u]);
	l = 0;
	while (l<u) {
		m = (l+u)/2;
		printf("\n%d",a[r][m]);
		if (a[r][m] == key) {
			*row = r; *col = m;
			return;
		}
		if (a[r][m] < key) {
			if (m == l)
				break;
			l = m;
		}
		else {
			if (m == u)
				break;
			u = m;
		}
	}
printf("\nCol");
	l = 0;	u = c;
	while (l < u) {
		m = (l+u)/2;
		printf("\n%d",a[m][c]);
		if (a[m][c] == key) {
			*row = m; *col = c;
			return;
		}
		if (a[m][c] < key) {
			if (m == l)
				break;
			l = m;
		}
		else {
			if (m == u)
				break;
			u = m;
		}
	}

	*row = -1; *col = -1;
}

void main() {
	int i, j, row, col, a[4][4] = {{1 ,2 ,3 ,4 },
								   {5 ,6 ,7 ,8 },
								   {9 ,10,11,12},
								   {13,14,15,16}};
	for (i=0; i<4; i++) {
		printf("\n");
		for (j=0; j<4; j++)
			printf("%d\t",a[i][j]);
	}
	search(a,4,8,&row,&col);
	printf("\n%d, %d\n", row, col);
}
