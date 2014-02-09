/*
design a method which consumes an integer and output the corresponding column number in Microsoft Excel ( ex. A, B, C......Z, AA, AB....ZZ....)
*/

# include <stdio.h>

void strrev(char* str) {
		int i=0, j=0;
		char swap;

		while(str[j]!='\0')
				j++;
		j--;

		while(i<j) {
				swap = str[i];
				str[i] = str[j];
				str[j] = swap;
				i++;
				j--;
		}
}

void convert(int num, char* col, int n) {
		char ch;
		while(num>=0) {
				ch = num % 26;
				col[n++] = 'A' + ch;
				num = num / 26 - 1;
		}
		col[n] = '\0';
}

void main() {
		int num = -1;
		char column[10] = "";
		convert(num, column, 0);
		strrev(column);
		printf("%s\n", column);
}
