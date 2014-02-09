/*
IP : {1,2,3,5,4,3,3,4,5,6,7,8}
OP : {3,4,5,6,7,8}
*/

# include <stdio.h>

void getLongestContinuousSequence(int *a, int n) {
		int ans_start = 0, ans_end = 0, start = 0, end = 0, i;
		for (i=0 ; i<n-1 ; i++) {
				if(a[i] + 1 == a[i+1])
						end++;
				else
						start = end = i+1;
				if (end - start > ans_end - ans_start) {
						ans_start = start;
						ans_end = end;
				}
		}

		for (i=ans_start ; i<=ans_end ; i++)
				printf("%d , ", a[i]);
		printf("\b\b  \n");
}

void main() {
		int a[12] = {1,2,3,5,4,3,3,4,5,6,7,8};
		getLongestContinuousSequence(a, 12);
}
