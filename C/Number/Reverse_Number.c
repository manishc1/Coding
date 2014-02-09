#include <stdio.h>

void main() {
		int num = 678 , rev = 0 , digit;
		while (num) {
				digit = num % 10;
				num = num / 10;
				rev = rev * 10 + digit;
		}
		printf("%d\n",rev);
}
