
# include <stdio.h>
#include<string.h>

void formImage(char* str, int l, int u, int* Image) {
	int i;
	for (i=0; i<26; i++)
		Image[i] = 0;
	i = l;
	while(i <= u) {
		Image[str[i] - ‘a’]++;
		i++;
	}
}

int matchAnagram(int* SImage, int* LImage) {
	int i;
	for (i=0; i <26; i++)
		if(SImage[i] != LImage[i])
			return 0;
	return 1;
}

int getAnagramCount(char* L, char* S) {
	int count = 0;
	int i, j;
	int SImage[26], LImage[26];
	int Slen = strlen(S);
	formImage(S, 0, Slen-1, SImage);
	int LLen = strlen(L);
	for (i=0; i<=L-S; i++) {
		formImage(L, i, i+SLen-1, LImage);
		if(matchAnagram(SImage, LImage))
			count++;
}
return count;
}

void main() {
		char S[] = "abc", L[] = "dabcd";
		getAnagramCount(L, S);
}
