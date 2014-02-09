# include <stdio.h>

void printpattern(char *str, int i) {
		if (str[i] == '\0')
				printf("%s\n", str);
		if (str[i] == '0' || str[i] == '1')
				printpattern(str, i+1);
		if (str[i] == '?') {
				str[i] = '0';
				printpattern(str, i+1);
				str[i] = '1';
				printpattern(str, i+1);
				str[i] = '?';
		}
}
void main() {
		char str[] = "1?00?101";
		printpattern(str, 0);
}
