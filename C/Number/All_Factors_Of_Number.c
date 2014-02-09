


A  = a1^b1 * a2^b2 * … an^bn

M = sigma bi
Total = [C(M,1) + C(M,2) … C(M,M)] / Product(bi)

100 = 2^2 * 5^2

1, 2, 4, 5, 10, 20, 25, 50, 100

M = 4
(4 + 6 + 4 + 1)

10 = 2 * 5

2*2 5*1 %
1 2

A = 2 5
B = 1 1

1
1*2
1*5
2*5
5*2

getFactors(int* A, int Alen, int* B, Blen, int* Factor, int FactorLen) {
	int i, j, k;
	for (i=0; i<Alen; i++) {
		if(B[i] > 0) {
			B[i]--;
			k = 0;
			for (j=0 ; j<FactorLen ; j++) {
				fac = Factor[j] * A[i];
				if(!isPresent(fac, Factor, FactorLen))
					Factor[FactorLen+k++] = fac;
			}
	getFactors(A,Alen,B,Blen,Factor,FactorLen+k);
		}
}
}

A = 2 5
B = 2 2


1
1 2



