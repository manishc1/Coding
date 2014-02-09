/*
We define C(n) as the number of ways to take n identical objects out of a bucket, where objects may be taken 1, 2, or 3 at a time. 

Example: C(4)=7, because you can take 4 objects in the following 7 ways: 
1,1,1,1 
2,1,1 
1,2,1 
1,1,2 
2,2 
3,1 
1,3 

Write a function for C(n) in the language of your choice.
*/

# include <stdio.h>

int Count(int n) {
		int i, count = 0;
		if (n == 0 || n == 1)
				return 1;
		if (n == 2)
				return 2;
		return Count(n - 3) + Count(n - 2) + Count(n - 1);
}

void main() {
		printf("%d\n",Count(5));
}
