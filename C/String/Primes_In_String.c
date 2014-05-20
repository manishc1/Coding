#include <stdio.h>

int isDigit(char c) {
    if ('0' <= c && c <= '9')
        return 1;
    return 0;
}

int isPrime(int num) {
    int i;
    if (num == 1 || num == 0)
        return 0;
    for (i=2 ; i*i <= num ; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int getNum(char* d, int n) {
    int num = 0;
    int i = 0;
    while(i<n) {
        num = num * 10 + (d[i] - '0');
        i++;
    }
    return num;
}

void printPrimesHelper(char *s, int n, char* d, int i) {
    int num = getNum(d, i);
    if (isPrime(num))
        printf("%d, ", num);
        
    if (isDigit(s[n])) {
        d[i] = s[n];
        printPrimesHelper(s, n+1, d, i+1);
    }
}

void printPrimes(char* s) {
    int i = 0;
    char d[100];
    while(s[i] != '\0') {
        if (isDigit(s[i])) {
            d[0] = s[i];
            printPrimesHelper(&s[i], 1, d, 1);
        }
        i++;
    }
}

void main()
{
    char s[100] = "abc2134d3";
    printPrimes(s);
}