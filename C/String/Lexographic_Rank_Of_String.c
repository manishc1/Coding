int rank (char *str, int l, int u) {
		if (u - l + 1 <= 0)
				return 0;

		int count = 0;
		for (int i=l+1; i<=u; i++)
				if (str[i] < str[l])
						count++;
		return count*factorial(u-l+1) + rank(str, l+1, u);
}
