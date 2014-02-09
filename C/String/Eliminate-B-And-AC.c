/*
Eliminate all ‘b’ and ‘ac’ in an array of characters, you have to replace them in-place, and you are only allowed to iterate over the char array once. 

Examples: 
abc -> ac 
ac->'' 
react->rt
 */

# include <stdio.h>

void main() {
		char s[100] = "ebbbbcaca";
		int i = 0, j = 0, k = 0;
		while (s[i] != '\0') {
				if (s[i] == 'b') {
						i++;
						continue;
				}
				if (s[i] == 'a') {						
						k = 1;
						while(s[i+k] == 'b')
								k++;
						if (s[i+k] == 'c') {
								i = i+k+1;
								continue;
						}
				}
				s[j] = s[i];
				i++;
				j++;
		}
		s[j] = '\0';
		printf("%s\n", s);
}
