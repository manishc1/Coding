/*
Given two strings .Print all the interleavings of the two strings. 
Interleaving means that the if B comes after A .It should also come after A in the interleaved string. 
ex- 
AB and CD 
ABCD 
ACBD 
ACDB 
CABD 
CADB 
CDAB
*/

#include<stdio.h>

void copy(char *str, char*s, int n) {
		while(*str != '\0') {
				s[n] = *str;
				str++;
				n++;
		}
		s[n] = '\0';
}

void interleave(char* s1, char* s2, char* s, int n) {
		if(*s1 == '\0') {
				copy(s2, s, n);
				printf("%s\n", s);		
				return;
		}
		if(*s2 == '\0') {
				copy(s1, s, n);
				printf("%s\n", s);		
				return;
		}
		s[n] = *(s1);
		interleave(s1+1, s2, s, n+1);
		s[n] = *(s2);
		interleave(s1, s2+1, s, n+1);
}

void main() {
		char s1[] = "ABC";
		char s2[] = "DEF";
		char s[10] = "";
		interleave(s1, s2, s, 0);
}
