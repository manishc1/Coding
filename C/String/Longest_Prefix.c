# include <stdio.h>
# include <string.h>

void findPrefix(char strings[10][10], int n, char prefix[10]) {
		int i, j;
		if(n == 0)
				return;
		strcpy(prefix, strings[0]);
		for (i=1; i<n; i++) {
				j = 0;
				while(prefix[j]==strings[i][j] && prefix[j]!='\0' && strings[i][j]!='\0')
						j++;
				prefix[j]='\0';
		}
}

void main() {
		char strings[10][10] = {"abc0", "abc1", "abc2"};
		char prefix[10] = "";
		int n = 3;
		findPrefix(strings, n, prefix);
		printf("Prefix = %s\n", prefix);
}
