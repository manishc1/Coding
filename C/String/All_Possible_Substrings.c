/*
Generate all the possible substrings using the characters of a given string. Write code. (The order of chars do not matter, i.e., ac <=> ca) 
i/p: abc 
o/p: { a,b,c,ab,ac,bc,abc} 
*/

# include <stdio.h>
# include <string.h>

void printSubStrings(char* str, int start, int end, char* substr, int n) {
		if (start > end)
				return;
		int i;
		for(i=start ; i<=end ; i++) {
				substr[n] = str[i]; substr[n+1] = '\0';
				printf(" %s ", substr);
				printSubStrings(str, i+1, end, substr, n+1);
		}
}

void main() {
		char str[] = "abcd";
		char substr[10] = "";
		printSubStrings(str, 0, strlen(str)-1, substr, 0);
}
