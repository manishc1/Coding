/*
Given an array of strings of 0s and 1s. X and Y are also given. Return the maximum number of elements in a subset of the array elements which will X number of zeroes and Y number of 1s when combined. For eg: if array[] = {"01", "10", "0", "110"} X=3, Y=2 
Answer should be 3 since first 3 strings when combined will give the required number of 0s and 1s.
*/

# include <stdio.h>

#define MAX 10
#define N 4

int maximum(int a, int b) {
		return (a >= b) ? a : b;
}

int getCount(char* s, char ch) {
		int len = 0;
		while(*s != '\0') {
				if(*s == ch)
						len++;
				s++;
		}
		return len;
}

void maxSizeOfSubset(char arr[][MAX], int i, int X, int Y, int* curr, int* max) {
		*max = maximum(*curr, *max);
		if(i >= N)
				return;
		int x = getCount(arr[i], '0');
		int y = getCount(arr[i], '1');
		if(X-x >= 0 && Y-y >= 0) {
				(*curr)++;
				maxSizeOfSubset(arr, i+1, X-x, Y-y, curr, max);
				(*curr)--;
		}
		maxSizeOfSubset(arr, i+1, X, Y, curr, max);
}

void main() {
		char arr[N][MAX] = {"01", "10", "0", "110"};
		int X = 3, Y = 3, max = 0, curr = 0;
		maxSizeOfSubset(arr, 0, X, Y, &curr, &max);
		printf("%d\n", max);
}
