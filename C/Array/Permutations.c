/*
Print all permutations
*/

# include <stdio.h>

void print(int *b, int blen) {
	int i;
	for (i=0; i<blen; i++)
		printf("%d", b[i]);
	printf("\n");
}

void permute (int *a, int alen, int *b, int blen) {
		int newa[10], i, j;
		if (alen == 0) {
				print(b, blen);
				return;
		}
		
		for (i=0; i<alen; i++) {
				b[blen] = a[i];
				
				// copy a in newa without a[i]
				/*for (j=0; j<i; j++)
						newa[j] = a[j];
				for (j=i; j<alen-1; j++)
						newa[j] = a[j+1];
				permute (newa, alen-1, b, blen+1);*/

				int tempi = a[i];
				a[i] = a[0];
				permute (&a[1], alen-1, b, blen+1);
				a[i] = tempi;
		}	
}

void swap(int* x, int* y) {
		int temp;
		temp = *x;
		*x = *y;
		*y = temp;
}

void permuteInPlace(int* a, int alen, int index) {
		int i;
		if (alen == index) {
				print(a, alen);
				return;
		}
		for(i=index; i<alen; i++) {
				swap(&a[i], &a[index]);
				permuteInPlace(a, alen, index+1);
				swap(&a[i], &a[index]);
		}
}

void main () {
		int a[10] = {9,8,1}, b[10] ;
		//permute (a, 3, b, 0);
		permuteInPlace(a, 3, 0);
}
