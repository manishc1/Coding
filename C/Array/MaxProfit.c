#include <stdio.h>

void main() {
		int a[8]={-2,4,30,-59,119,-60,100,117};
		int i, MinSoFar=999, buy, sell, MaxProfit=0, newprofit=0;

		for (i=0; i<8; i++) {
				if (a[i] < MinSoFar)
						MinSoFar = a[i];
				newprofit = a[i] - MinSoFar;
				if (newprofit > MaxProfit) {
						MaxProfit = newprofit;
						buy = MinSoFar;
						sell = a[i];
				}
				printf("%d, %d\n",a[i],MaxProfit);
		}

		printf("Buy at %d\nSell at %d\n",buy, sell);
}
