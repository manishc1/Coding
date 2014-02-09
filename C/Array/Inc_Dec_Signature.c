/*
You are given an array of n elements [1,2,....n]. For example {3,2,1,6,7,4,5}. 
Now we create a signature of this array by comparing every consecutive pir of elements. If they increase, write I else write D. For example for the above array, the signature would be "DDIIDI". The signature thus has a length of N-1. Now the question is given a signature, compute the lexicographically smallest permutation of [1,2,....n]. Write the below function in language of your choice. 

vector* FindPermute(const string& signature);
*/

/*
start from 0.
For D - decrease by 1
For I increase by 1
Find min
if min < 1, then diff = 1 - min and add diff to every element
*/
