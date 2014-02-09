A = [ 3 , 7, 19, 30 ]
B = [ 1 , 7 , 30, 191 ]

intersect(A, B) => [ 7 , 30 ]



time : O(max(Asize,Bsize))
space: O(min(Asize,Bsize))

xor = 3 ^ 7....^1^7....
	A	B

xor =0100 ^ 0110 = 0010
 

int binarySearch(int key, int *a, int l, int u) {
	int m;
	while (l<=u) {
		m = (l+u)/2;
		if (a[m] == key)
			return 1;
		else if (a[m] > key) {
			u = m-1;
		}
		else {
			l = m+1;
		}
	}
	return 0;
}

void findIntersection(int *a, int alen, int *b, int blen) {
	int i;

	for (i=0 ; i<blen ; i++) {
		if(binarySearch(b[i], a, 0, alen-1))
			printf (“%d , ”, b[i]);
	}
}



void intersection(int *a, int alen, int *b, int blen) {
	int i=0, j=0;
	while (i < alen && j < blen) {
		if (a[i] == b[j]) {
			printf(“%d ”, a[i]);
			i++;
			j++;
		}
		else if (a[i] < b[j])
			i++;
		else
			j++;
	}
}
