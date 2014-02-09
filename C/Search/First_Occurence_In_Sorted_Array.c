#include <stdio.h>


void findfirstinstance(int a[], int lower, int upper, int num) {
		int mid = (lower+upper)/2;
		if((lower + 1 == upper) || (lower == upper)) {
				if(a[lower] == num)
						printf("\nInstance at %d\n",lower);
				else if (a[upper] == num)
						printf("\nInstance at %d\n",upper);
				else
						printf("\n%d not found\n",num);
		}
		else if(a[mid] < num)
				findfirstinstance(a, mid, upper, num);
		else
				findfirstinstance(a, lower, mid, num);
}


int main() {
		int a[10], i, lim, num;
		printf("\nLimit :: ");
		scanf("\n%d",&lim);
		for(i=0 ; i<lim ; i++) {
				printf("\na[%d] = ",i);
				scanf("%d",&a[i]);
		}

		printf("\nNumber :: ");
		scanf("%d",&num);

		findfirstinstance(a, 0, lim-1, num);
		return 1;
}
