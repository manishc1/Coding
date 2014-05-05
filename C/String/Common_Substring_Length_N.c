# include <stdio.h>
# include <string.h>

int hasCommonSubstring(char* str1, int l1, int s1i, char* str2, int l2, int s2i, int N) {
		int i1, i2, count;
		if(s1i >= l1 || s2i >= l2)
				return 0;
		if(str1[s1i] == str2[s2i]) {
				i1=s1i;
				i2=s2i;
				count = 0;
				while(i1<l1 && i2<l2 && str1[i1]==str2[i2]) {
						count++;
						i1++;
						i2++;
				}
				if (count == N)
						return 1;
		}
		return hasCommonSubstring(str1, l1, s1i+1, str2, l2, s2i, N) |
				hasCommonSubstring(str1, l1, s1i, str2, l2, s2i+1, N);
}

void main(){
		char str1[] = "1223456", str2[] = "2347";
		int N = 3;
		printf("---%d\n", hasCommonSubstring(str1, strlen(str1), 0, str2, strlen(str2), 0, N));
}
