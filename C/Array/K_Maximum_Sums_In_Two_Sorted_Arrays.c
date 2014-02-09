/*
Given two sorted arrays of numbers, we want to find the pair with the kth largest possible sum. (A pair is one element from the first array and one element from the second array). For example, with arrays

[2, 3, 5, 8, 13]
[4, 8, 12, 16]
The pairs with largest sums are

13 + 16 = 29
13 + 12 = 25
8 + 16 = 24
13 + 8 = 21
8 + 12 = 20
So the pair with the 4th largest sum is (13, 8). How to find the pair with the kth largest possible sum?

I am looking for a solution involving either a min heap or a max heap.
*/

heap.add(pair(0, 0));  // biggest pair

// remove max k-1 times
for (int i = 0; i < k - 1; ++i) {
    // get max and remove it from the heap
    max = heap.popMax();

    // add next candidates
    heap.add(pair(max.i + 1, max.j));
    heap.add(pair(max.i, max.j + 1));
}

// get k-th maximum element
max = heap.popMax();
maxVal = a[max.i] + b[max.j];


#include<stdio.h>

void getKMaxSums(int* A, int Alen, int* B, int Blen) {
				 if(Alen < 1 || Blen < 1)
						 return;
				 
		 }
void main() {
				 int A[5] = {2,3,5,8,13};
				 int B[4] = {4,8,12,16};
				 getKMaxSums(A, 5, B, 4);
		 }
