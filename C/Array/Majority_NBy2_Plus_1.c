/*
Find the majority number in a given sequence of numbers (a number that occurs more than N/2 times where N is the count of numbers in the sequence). Don't maintain a map of all occurring numbers along with a count. No number may be a majority. 

Example: 1 1 2 3 4 1 6 1 7 1 1 
Majority number is 1 since it occurs 6 times (> 11/2)
*/

# include <stdio.h>

void main() {
		int array[11] = {11, 1, 2, 3, 4, 1, 6, 1, 1, 1, 7};
		int i, num = array[0], count = 1;

		for (i = 1 ; i < 11 ; i++) {
				if (array[i] == num)
						count++;
				else if (count == 0) {
						num = array[i];
						count++;					   
				} else {
						count--;
				}
		}
		count = 0;
		for (i = 0 ; i < 11 ; i++)
				if (array[i] == num)
						count++;
		if (2*count > 11)
				printf("%d\n", num);
		else
				printf("No Majority\n");
}
