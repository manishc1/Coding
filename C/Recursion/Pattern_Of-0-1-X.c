/*
Given a string pattern of 0s, 1s, and ?s (wildcards), generate all 0-1 strings that match this pattern. 
e.g. 1?00?101 -> [10000101, 10001101, 11000101, 11001101]. 
You can generate the strings in any order that suits you.
*/

# include <stdio.h>

void printPatterns(char* pattern, int i) {
		switch(pattern[i]) {
		case '\0':
				printf("%s\n", pattern);
				break;
		case '?':
				pattern[i] = '0';
				printPatterns(pattern, i+1);
				pattern[i] = '1';
				printPatterns(pattern, i+1);
				pattern[i] = '?';
				break;
		case '0':
		case '1':
				printPatterns(pattern, i+1);
		}
}

void main() {
		char pattern[9] = "1?0??101";
		printPatterns(pattern, 0);
}
