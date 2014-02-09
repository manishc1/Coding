# include <stdio.h>

int kmax(int *a, int alen, int *b, int blen, int k) {
		int kby2 = k/2;

		printf ("\n a[0]=%d, alen=%d, b[0]=%d, blen=%d, k=%d, kby2=%d",a[0],alen,b[0],blen,k,kby2);
		if (k == 0)
				return -1;
		if (k == 1) {
				if (alen > 0 && blen > 0)
						return a[0]>=b[0]?a[0]:b[0];
				else if (alen > 0)
						return a[0];
				else if (blen > 0)
						return b[0];
				return -1;
		}

		if (alen > 0 && blen > 0) {
				if (a[kby2-1] < b[kby2-1])
						return kmax(a,alen,&b[kby2],blen-kby2,k-kby2);
				return kmax(&a[kby2],alen-kby2,b,blen,k-kby2);
		}
		else if (alen > 0)
				return kmax(&a[kby2],alen-kby2,b,blen,k-kby2);
		else if (blen > 0)
				return kmax(a,alen,&b[kby2],blen-kby2,k-kby2);
		return -1;
}

void main() {
		int a[10] = {14,13,12,11,10,4,3,2,1,0};
		int b[10] = {19,18,17,16,15,9,8,7,6,5};
		int k = 2;

		printf("\n%d\n", kmax(a,10,b,10,k));
}
