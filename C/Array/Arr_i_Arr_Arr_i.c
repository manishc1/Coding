/*
WAP to modify the array such that arr[I] = arr[arr[I]]. 
Do this in place i.e. with out using additional memory. 

example : if a = {2,3,1,0} 
o/p = a = {1,0,3,2} 

Note : The array contains 0 to n-1 integers.
*/

//  set A'[i] = A[i] + N * A[A[i]]
    for(int i = 0; i < N; i++)
        A[i] += (A[A[i] % N] % N) * N;

    for(int i = 0; i < N; i++)  
        A[i] /= N;
