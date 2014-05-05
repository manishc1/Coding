# include <stdio.h>
# include <stdlib.h>

void allParanthesisHelper(char* s, int i, int n1, int n2) {
  if(n1 == 0 && n2 == 0) {
    s[i] = '\0';
    printf("%s\n", s);
    return;
  }

  if (n1 > 0) {
    s[i] = '(';
    allParanthesisHelper(s, i+1, n1-1, n2);
  }

  if (n1>n2) {
    s[i] = ')';
    allParanthesisHelper(s, i+1, n1, n2-1);
  }
}

void allParanthesis(int n) {
  char* s = (char*) malloc (sizeof(char)*2*n+1);
  allParanthesisHelper(s, 0, n, n);
}

void main() {
  int n = 1;
  allParanthesis(n);
}