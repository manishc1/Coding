/*
Given a sorted array, output all triplets <a,b,c> such that a-b = c. Expected time is O(n^2). My approach using binary search took O(n^2 logn). When you attempt an approach, test your code with this example and list your outputs for verification. Thanks. 
-12, -7, -4, 0, 3, 5, 9, 10, 15, 16
*/

# include <stdio.h>

# define N 10

void printTriplets(int* arr) {
		int i,j,k;
		for (i=N-1 ; i>=0 ; i--) {
				j=0; k=N-1;
				while(j<k) {
						if (j==i) {
								j++;
								continue;
						}
						if (k==i) {
								k--;
								continue;
						}
						if (arr[j] + arr[k] == arr[i]) {
								printf("a(%d) - b(%d) = c(%d)\n", arr[i], arr[j], arr[k]);
								//printf("a(%d) - b(%d) = c(%d)\n", arr[i], arr[k], arr[j]);																
								j++;
								k--;
						} else if (arr[j] + arr[k] < arr[i])
								j++;
						else
								k--;
				}
		}
}

void main() {
		int arr[N] = {-12, -7, -4, 0, 3, 5, 9, 10, 15, 16};
		printTriplets(arr);
}
