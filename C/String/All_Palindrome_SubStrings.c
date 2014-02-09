/*
Write a program that prints all the sub string that is palindrome within a input String. For e.g For input String "abbcacbca" output should be: [cac, bcacb, cbc, acbca, bb]
*/

# include <stdio.h>
# include <string.h>

void printString(char* str, int i, int j) {
		while(i <= j) {
				printf("%c", str[i]);
				i++;
		}
		printf("\n");
}

int isPalindrome(char* str, int i, int j) {
		while(i<j) {
				if(str[i] != str[j])
						return 0;
				i++;
				j--;
		}
		return 1;
}

void printPalindromeSubstrings(char* str, int i, int j) {
		if (i >= j)
				return;
		if(isPalindrome(str, i, j))
				printString(str, i, j);
		printPalindromeSubstrings(str, i, j-1);
		printPalindromeSubstrings(str, i+1, j);
}

void main() {
		char str[10] = "abbcacbca";
		printPalindromeSubstrings(str, 0, strlen(str)-1);
}
