/*
Implement LookAndSay function. For example, first, let user input a number, say 1. Then, the function will generate the next 10 numbers which satisfy this condition: 
1, 11,21,1211,111221,312211... 

1
^ one 1s -> 11
^ two 1s -> 21
^ one 2s one 1s -> 1211
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void main() {
		char *look = malloc(2), *say;
		int i, j, count, limit = 10;

		strcpy(look, "1");


		while(limit-- > 0) {
				printf("%s\n", look);
				say = realloc(say, 2*strlen(look)+1);
				j = 0;
				count = 1;
				for(i=0; i<strlen(look); i++) {
						if(look[i] == look[i+1])
								count++;
						else {
								j += sprintf(say+j, "%d%c", count, look[i]);
								count = 1;
						}
				}
				strcpy(look, say);
		}
}
