# include <stdio.h>
# include <string.h>

int formNum(int digLen, char* num) {
		int i, n=0;
		for(i=0; i<digLen; i++) {
				n = n * 10 + (num[i]-'0');
		}
		return(n);
}

int isSumValid(int digLen, char* num) {
		if(formNum(digLen, &num[0]) + formNum(digLen, &num[digLen]) == formNum(digLen, &num[2*digLen]))
				return(1);
		return(0);
}

int isFibonacciNumber(char* num) {
		int digLen, i, flag;
		for(digLen=1; digLen<=strlen(num)/3; digLen++) {
				i=0;
				flag = 0;
				while(i <= strlen(num) - 3*digLen) {
						if(!isSumValid(digLen, &num[i])) {
								flag = 1;
								break;
						}
						i += digLen;
				}
				if(flag == 0)
						return(1);
		}
		return(0);
}

void main() {
		char num[] = "10102030";
		if(isFibonacciNumber(num))
				printf("Yes\n");
		else
				printf("No\n");
}
