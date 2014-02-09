/*
A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N. 
E.g.:
The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps.
Write a function: class Solution { public int binary_gap(int N); } that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.
*/

int solution(int N) {
    int maxGap = 0, currGap = 0, inGapFlag = 0;
    while(N) {       
        if(N & 0x1) {
            if(inGapFlag && (currGap > maxGap))
                maxGap = currGap;
            inGapFlag = 1;
            currGap = 0;
        } else {
            currGap++;
        }
        N >>= 1;
    }
    return maxGap;
}
