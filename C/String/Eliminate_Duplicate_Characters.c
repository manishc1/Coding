#include <stdio.h>
#include <string.h>


void eliminateDuplicate(char* str)
{
		char hash[256];
		int i,j;

		for (i=0 ; i<256 ; i++) {
				hash[i] = 0;
		}

		for (i=0 ; i<strlen(str) ; i++) {
				hash[str[i]]++;
		}

		for (i=0,j=0 ; i<strlen(str) ; i++) {
				if(hash[str[i]] == 1)
						str[j++] = str[i];
				else if(hash[str[i]] > 1) {
						str[j++] = str[i];
						hash[str[i]] = -1;
				}
		}
		str[j] = '\0';
}


int main()
{
		char str[100];
		printf("String :: ");
		scanf("\n%s",str);
		eliminateDuplicate(str);
		printf("New String :: %s\n",str);
		return 1;
}
