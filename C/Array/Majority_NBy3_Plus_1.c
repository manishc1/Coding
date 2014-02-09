/*
Design an algorithm that, given a list of n elements in an array, finds all the elements that appear more than n/3 times in the list. The algorithm should run in linear time ( n >=0 ) 

You are expected to use comparisons and achieve linear time. No hashing/excessive space/ and don't use standard linear time deterministic selection algo
*/

# include <stdio.h>

void main() {
		int array[11] = {11, 1, 2, 3, 4, 11, 6, 12, 1, 1, 7};
		int i, num[2], count[2] = {0}, flag;

		for (i = 0 ; i < 11 ; i++) {
				if (num[0] == array[i])
						count[0]++;
				else if (num[1] == array[i])
						count[1]++;
				else if (count[0] == 0) {
						num[0] = array[i];
						count[0]++;					   
				} else if(count[1] == 0) {
						num[1] = array[i];
						count[1]++;
				}else {
						count[0]--;
						count[1]--;
				}
		}
		count[0] = count[1] = 0;
		for (i = 0 ; i < 11 ; i++) {
				if(array[i] == num[0])
						count[0]++;
				if(array[i] == num[1])
						count[1]++;
		}

		flag = 0;
		if (3*count[0] > 11) {
				printf("%d\n", num[0]);
				flag = 1;
		}
		if (3*count[1] > 11) {
				printf("%d\n", num[1]);
				flag = 1;
		}
		if(!flag)
				printf("No Majority\n");
}
