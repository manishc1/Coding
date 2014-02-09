/*
given a maze (matrix bool[N][M]) where 0 = free way, 1 = obstacle - How many ways are there to reach from [0][0] to [N][M]? write a non-recursive solution.
*/

int ways(int *bool, int n, int m) {
	int count=0, i, j, stack[100], top=-1;

	if (bool[0][0]==1 || bool[n-1][m-1]==1)
		return 0;

	stack[++top] = 0; stack[++top] = 0;		//push

	while(top!=-1) {
		j = stack[top--]; i = stack[top--];	//pop
		if (bool[i][j]==1)
			continue;
		if (i == n-1 && j == m-1) {
			count++;
			continue;
		}
		if (i+1 < n) {
			stack[top++] = i+1; stack[top++] = j;
		}
		if (j+1 < m) {
			stack[top++] = i; stack[top++] = j+1;
		}
	}

	return count;
}
