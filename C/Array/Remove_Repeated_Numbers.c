/*
1, 2, 3, 3, 3, 2, 6
1, 2,          2, 6  ->  1, 2, 2, 6
1, 6
*/

# include <stdio.h>

int removeRepeated(int* arr, int n) {
		int i, j, k;
		i=0;
		while(i<n) {
				j = i;
				while(arr[i] == arr[j])
						j++;
				// no repetition
				if(j - i == 1) {
						i++;
						continue;
				}
				// repetition
				k = 0;
				while(j+k < n) {
						arr[i+k] = arr[j+k];
						k++;
				}
				n -= (j-i);
				if(i>0)
						i--;
		}
		return(n);
}

void main() {
		int arr[7] = {2,2,3,3,3,2,6}, n, i;
		n = removeRepeated(arr, 7);
		for(i=0 ; i<n ; i++) {
				printf("%d, ", arr[i]);
		}
		printf("\n");
}
