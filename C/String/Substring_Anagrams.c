Large String (L)
Small String (S)

S = abc
L = dbacb

S = ababababab
L = aaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb


Hash(abc) = 1234

S (abc) = [a=1 b=1 c=1 ?=0] 2*3*5
Sub(bac) =[a=1 b=1 c=1 ?=0] 3*2*5

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
	for (i=0; i<26; i++)
		if(SImage[i] != LImage[i])
			return 0;
	return 1;
}

void modify(char prev, char curr, int* LImage) {
	LImage[prev-’a’]--;
	LImage[curr-’a’]++;
}

int getAnagramCount(char* L, char* S) {
	int count = 0;
	int i, j;
	int SImage[26], LImage[26];
	int Slen = strlen(S);
	int LLen = strlen(L);
	if (LLen < SLen)
		return 0;

	formImage(S, 0, Slen-1, SImage);
	formImage(L, 0, SLen-1, LImage);

	for (i=0; i<=LLen-SLen; i++) {
		if(i > 0)
			modifyImage(L[i-1], L[i+SLen-1], LImage);
		if(matchAnagram(SImage, LImage))
			count++;
}
return count;
}
