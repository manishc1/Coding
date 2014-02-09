#include <stdio.h>

/*
  Eg : 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1

  Approach 1 : As below
  Approach 2 : Memoize if visited (while doing 22, memoize to skip 11, 34, ...)
  Approach 3 : tree from 1 (left /2, right *3+1), return number at max level.
*/

# define MAXLEN 1000
int getMax(int i, int j) {
		int count[MAXLEN] = {0}, num, max = 0, n;
		for (n=i; n<=j; n++) {
				num = n;
				if (count[n]) {
						printf ("%d , ", count[n]);
						if (count[n] > max)
								max = count[n];
						continue;
				}
				while (1) {
						if (num == 1) {
								count[n] ++;
								break;
						}
						if (count[num]) {
								count[n] += count[num];
								break;
						}
						else {
								if(!(num & 1))
										num = num >> 1;
								else
										num = (num << 1) + num + 1;
								count[n] ++;
						}
				}
				printf("%d , ", count[n]);
				if (count[n] > max) {
						max = count[n];
				}
		}

		return max;
}

void main() {
		int max = getMax(20, 22);
		printf ("\n%d\n",max);
}
