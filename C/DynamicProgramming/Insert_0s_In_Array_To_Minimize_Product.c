/*
Given 2 arrays A,B, where x(A.length) < y(B.length), we want to 
insert (y - x) 0's to A at various places such that A*B is minimum. For instance, if A = (1, -1) and 
B = (1,2, 3, 4), then inserting two 0's in the middle of A such that A = (1, 0, 0, -1) would minimize 
A*B. I think he was looking for a dynamic problem solution.
*/

/*
Approach:

Sub problem: 

Try to find the solution (Sol[i,j]) for A[1...i] and B[1...j] where 1 <= i <= x and 1 <= j <= y. 

We get the recurrence relation: 

Sol[i,j] = min {A[i]*B[j] + Sol[i-1, j-1], Sol[i, j-1]} 

The first term corresponds to multiplying B[j] by A[j] and the second term corresponds to multiplying B[j] by 0. 

Since the recurrence step is O(1), the complete algorithm is O(yx).
*/
