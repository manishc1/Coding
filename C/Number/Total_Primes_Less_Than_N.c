/*
write the most efficient (in terms of time complexity) function getNumberOfPrimes which takes in an integer N as its parameter. 

to return the number of prime numbers that are less than N 

Sample Testcases: 
Input #00: 
100 
Output #00: 
25 

Input #01: 
1000000 
Output #01: 
78498
*/

int count(int N) {
	int primes[N], n=0, i, flag;
	if (N <= 0)	return 0;
	if (N < 3)	return N-1;

	primes[n++] = 2;

	for (i=3; i<N; i+=2) {
		for (j=0; j<n; j++)
			if(i%primes[j] == 0) {
				break;
		if (j == n) {
			primes[n++] = i;
		}
	}

	return n;
}
