/*
LIS(i) = max{LIS(j)+1} if j<i, a[j]<a[i]
return max LIS(i)
*/

# include <stdio.h>

void LISHelper(int *a, int n, int *m, int i) {
	int j;
	for (j=0; j<i; j++)
		if(a[j]<a[i])
			if (m[i]<m[j]+1)
				m[i] = m[j]+1;
}

int LIS(int *a, int n) {
	int m[10] = {1}, i, max = 0;	
	for (i=0; i<n; i++) {
		LISHelper(a,n,m,i);
		if (m[i] > max)
			max = m[i];
	}
	for (i=0; i<n; i++)
		printf("\n%d , ", m[i]);
	return max;
}

void main() {
	int a[6] = {0,2,1,3,5,4};
	printf("LIS = %d", LIS(a, 6));
}
