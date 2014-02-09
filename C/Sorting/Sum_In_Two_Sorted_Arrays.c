# include <stdio.h>

void main() {
		int a[5] = {2, 4, 10, 11, 14};
		int b[5] = {8, 13, 14, 16, 20};
		int i=0, j=4;
		int sum = 17;
		while(i<5 && j>=0) {
				printf("%d, %d, %d\n", a[i], b[j], a[i]+b[j]);
				if(a[i] + b[j] == sum) {
						printf("a[%d]=%d & b[%d]=%d\n", i, a[i], j, b[j]);
						break;
				}
				if(a[i] + b[j] > sum)
						j--;
				else
						i++;
		}
}
