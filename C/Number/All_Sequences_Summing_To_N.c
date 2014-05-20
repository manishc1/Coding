#include <stdio.h>
#include <stdlib.h>

void print(int* seq, int n) {
    int i;
    printf("\n");
    for (i=0; i<n ;i++) {
        printf("%d, ", seq[i]);
    }
}

void printSeqSummingToNum(int num, int* seq, int i) {
    int j;
    
    if (num == 0) {
        return;
    }
    
    for (j = 1; j < num ; j++) {
        seq[i] = j;
        seq[i+1] = num - j;
        print(seq, i+2);
        printSeqSummingToNum(num-j, seq, i+1);
    }
}

void main()
{
   int num = 4, i = 0;
   int *seq = (int*)malloc(sizeof(int)*num);
   printSeqSummingToNum(num, seq, i);
}
