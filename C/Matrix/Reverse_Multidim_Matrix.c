/*
Given a multidimensional array with only 0s and 1s, reverse the array! I guess what he meant was flip 0s to 1s and vice versa! The array could be of any dimension ex:4X4X4X4....

(I dint get this q's so asked for another!)
*/

# include <stdio.h>

void reverse(void *dummy, int n) {
		int i;
		int *a = (int *) dummy;
		for (i=0 ; i<n ; i++)
				a[i] = a[i]^1;
}

void main() {
		int i,j,k;
		int a[2][2][2] = {{{0,1},{0,1}},{{1,0},{1,0}}};
		for (i=0 ; i<2 ; i++) {
				for(j=0 ; j<2 ; j++){
						for(k=0 ; k<2 ; k++)
								printf("%d ",a[i][j][k]);
						printf("\n");
				}
				printf ("\n");
		}

		reverse (a, 8);

		for (i=0 ; i<2 ; i++) {
				for(j=0 ; j<2 ; j++){
						for(k=0 ; k<2 ; k++)
								printf("%d ",a[i][j][k]);
						printf("\n");
				}
				printf ("\n");
		}
}
