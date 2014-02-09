# include <stdio.h>

void main () {
		int a[6] = {1,1,1,2,2,3}, i, ones=0, twos=0, not_threes=0;

		for (i=0; i<6; i++) {
				twos |= ones & a[i];
				ones ^= a[i];
				not_threes = ~(ones & twos);
				if (i == 6-1)
						break;
				ones &= not_threes;
				twos &= not_threes;
		}

		printf("%d, %d, %d\n", ones, twos, not_threes);
}
