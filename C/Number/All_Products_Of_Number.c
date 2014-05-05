/*
Write all the possible numbers which multiply to given number. Eg : 12 can be written as 12*1, 2*6,3*4,2*2*4. Dont include 6*2 again or 4*3 as its duplication of 2*6 and 3*4 resp.
*/

# include <stdio.h>

void print(int* factors, int i) {
		int j;
		for(j=0;j<i;j++)
				printf("%d * ", factors[j]);
}

void getProducts(int num, int* factors, int i) {
		int j;
		if (num <= 2) {
				return;
		}

		if (i == 0)
				j = 2;
		else
				j = factors[i-1];

		for (; j*j<num; j++) {
				if (num%j == 0) {
						print(factors, i);
						printf("%d * %d\n", j, num/j);
						factors[i] = j;
						getProducts(num/j, factors, i+1);
				}
		}
}

void main() {
		int num = 12;
		int factors[100], i=0;
		if (num == 1) {
				printf("1\n");
		} else {
				printf("1 * %d\n", num);
				getProducts(num, factors, i);
		}
}
