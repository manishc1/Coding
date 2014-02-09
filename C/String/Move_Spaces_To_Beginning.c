/*
Move the spaces to the starting of the string in a c style string. In place within one iteration.
*/

# include <stdio.h>
# include <string.h>

void move_spaces(char* str) {
		int i, j;
		char ch;
		i = j = strlen(str)-1;
		while(i>=0) {
				if (str[i] == '_') {
						i--;
						continue;
				}
				ch = str[i];
				str[i] = '_';
				str[j] = ch;
				i--;
				j--;
		}
}

void print(char* str) {
		int i;
		for (i=0 ; str[i]!='\0' ; i++)
				printf("%c",str[i]);
		printf("\n");
}

void main() {
		char str[100] = "I_am_in_a_palace.";
		print(str);
		move_spaces(str);
		print(str);
}
