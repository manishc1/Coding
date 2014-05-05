# include <stdio.h>

int getLongestUniqueLen(char* s) {
		int len = 0, pos[256], i, j;

		for(i=0; i<256; i++)
				pos[i] = -1;

		i=0; j=0;
		while(s[i] != '\0' && s[j] != '\0') {
				if(pos[s[j]] != -1) {
						if((j-i) > len)
								len = j-i;
						i = pos[s[j]] + 1;
				}
				pos[s[j]] = j;
				j++;
		}

		if (j-i > len)
				return j-i;
		return len;
}

void main() {
		char s[100] = "abcdaebc";
		int len = getLongestUniqueLen(s);
		printf("%s: %d\n",s, len);
}
