/*
Return a shortest prefix of <code>word</code> that is <em>not</em> a prefix of any word in the <code>list</code> 

e.g. 
word: cat, it has 4 prefixes: “”, “c”, “ca”, “cat” 
list: alpha, beta, cotton, delta, camera 
Result is “cat”
*/

#include<stdio.h>
#include<string.h>

void getShortestPrefix(char* word, char* list[10], int n, char* prefix) {
}

void main() {
		char word[10] = "cat";
		char list[5][10] = {"alpha", "beta", "cotton", "delta", "camera"};
		char prefix[10];
		int n = 5;
		int i, j, k;

		int wordIndex = 0;
		for(i=0 ; i<n ; i++) {
				for(j=0, k=0 ; j<strlen(list[i]) && k<strlen(word) ; j++, k++) {
						if(word[k] != list[i][j])
								break;
				}
				if(k > wordIndex)
						wordIndex = k;
		}

		if(wordIndex < strlen(word)) {
				printf("Prefix = ");
				for(i=0 ; i<=wordIndex ; i++)
						printf("%c", word[i]);
				printf("\n");
		} else {
				printf("No prefix\n");
		}	  
}
