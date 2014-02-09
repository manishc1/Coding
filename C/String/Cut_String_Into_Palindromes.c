/*
You are given a large string. You need to cut the string into chunks such that each substring that you get is a palindrome. Remember that each 1 length string is always a palindrome. You need to find the minimum number of cuts that you need to make such that each substring is a palindrome.
*/

# include <stdio.h>
# include <string.h>

int min(int a, int b) {
		return (a<=b) ? a : b;
}

void print(char* str, int start, int end) {
		while(start <= end)
				printf("%c", str[start++]);
		printf("\n");
}

int isPalindrome(char* str, int start, int end) {
		while(start < end) {
				if(str[start] != str[end])
						return 0;
				start++;
				end--;
		}
		return 1;
}

int cut(char* str, int start, int end) {
		int i, min_cut, min_i;
		if (isPalindrome(str, start, end)) {
				//print(str, start, end);
				return 0;
		}
		min_cut = end - start + 1;
		for (i = start ; i < end ; i++) {
				min_cut = min (min_cut, cut(str, start, i) + 1 + cut(str, i+1, end));
		}
		return min_cut;
}

void main() {
		char str[] = "abacdcefe";
		int min_cut = cut(str, 0, strlen(str)-1);
		printf("%d\n", min_cut);
}
