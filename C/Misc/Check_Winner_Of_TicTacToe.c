int check_winner(int * a) {
	int i, j, sum, sum1;

	for (i=0; i<n; i++) {
		sum = 0;
		for (j=0; j<n; j++)
			sum += a[i][j];
		if (sum == 0)	return 0;
		if (sum == 3)	return 1;
	}

	for (i=0; i<n; i++) {
		sum = 0;
		for (j=0; j<n; j++)
			sum += a[j][i];
		if (sum == 0)	return 0;
		if (sum == 3)	return 1;
	}

	sum = sum1 = 0;
	for (i=0; i<n; i++) {
		sum += a[i][i];
		sum1 += a[i][n-1-i];
	}
	if (sum == 0)	return 0;
	if (sum == 1)	return 1;

	return -1;
}