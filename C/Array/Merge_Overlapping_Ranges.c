void ranges (int *a, int n, int *b) {
		int m = 0, flag;
		int i, j;

		if (n < 2)
				return m;

		b[m++] = a[0];
		b[m++] = a[1];

		for (i=2 ; i<n ; i+=2) {
				flag = 0;
				for (j=0 ; j<m ; j+=2) {
						if (a[i] >= b[j] && a[i] <= b[j+1]) {
								if (a[i+1] > b[j+1])
										b[j+1] = a[i+1];
								flag = 1;
								break;
						}
				}
				if (!flag) {
						b[m++] = a[i];
						b[m++] = a[i+1];
				}
		}
}
