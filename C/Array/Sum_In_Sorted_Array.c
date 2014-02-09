#include <stdio.h>

void main() {
		int a[10] = {1,2,3,4,5,6,7,8,9};
		int sum = 0;
		int i = 0, j = 8, flag = 0;
		while(i<j) {
				if ((a[i]+a[j] == sum)) {
						printf("%d , %d\n",a[i], a[j]);
						flag = 1;
						break;
				}
				if ((a[i]+a[j]) < sum)
						i++;
				else
						j--;
		}
		if (!flag)
				printf("No Solution\n");
}
