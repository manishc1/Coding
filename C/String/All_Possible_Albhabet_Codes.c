/*
If a=1, b=2, c=3,....z=26. Given a string, find all possible codes that string can generate. Give a count as well as print the strings. 

For example: 
Input: "1123". You need to general all valid alphabet codes from this string. 

Output List 
aabc //a = 1, a = 1, b = 2, c = 3 
kbc // since k is 11, b = 2, c= 3 
alc // a = 1, l = 12, c = 3 
aaw // a= 1, a =1, w= 23 
kw // k = 11, w = 23
*/

# include <stdio.h>

int getNum(char* number, int len) {
		int i, num=0;
		for(i=0; i<len; i++) {
				num = num*10 + (number[i]-'0');
		}
		return num;
}

void allPossibleCodes(char* number, int i, int n, char* code, int k) {
		int len, num;

		if(i >= n) {
				code[k] = '\0';
				printf("%s\n", code);
				return;
		}

		for(len=1 ; len<=2 , i+len-1<n ; len++) {
				num = getNum(&number[i], len);
				if(num <= 26) {
						code[k] = 'a' - 1 + num;
						allPossibleCodes(number, i+len, n, code, k+1);
				}
		}
}

void main() {
		char number[] = "1123";
		char code[4];
		allPossibleCodes(number, 0, 4, code, 0);
}
