/*
A string is called sstring if it consists of lowercase english letters and no two of its consecutive characters are the same. 

You are given string s of length n. Calculate the number of sstrings of length that are not lexicographically greater than s. 
Input format 
The only line of input contains the string s. It's length is not greater than 100. 
All characters of input are lowercase english letters. 

Output format: 
Print the answer of test modulo 1009 to the only line of output. 

Sample input: 
bcd 

Sample output: 
653
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MOD 1009

int findRank(char* str) {
		int i, rank=0, count;
		int* a = (int*)malloc(sizeof(int)*strlen(str));

		a[strlen(str)-1] = 1;
		for (i=strlen(str)-2; i>=0; i--)
				a[i] = (a[i+1]*25) % MOD;

		for(i=0; i<strlen(str); i++) {
				count = str[i] - 'a';
				if(i>0 && str[i] > str[i-1])
						count--;
				rank += (count * a[i]) % MOD;
		}

		return (rank + 1) % MOD;
}

void main() {
		char str[10] = "bcd";
		int rank;
		rank = findRank(str);
		printf("%d\n", rank);
}
