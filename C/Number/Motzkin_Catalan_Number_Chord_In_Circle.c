/*
Given 2n points on a circle.find the number of ways to draw n non intersecting chords.
*/

rec_calc(n) {
		if (n is Odd)
				return 0;
		if (n is 1)
				return 1;
		if (n==2)
				return 1;
		else
				for (i from 2 to n) {
						sum += rec_calc(i-2) * rec_calc(n-i);
				}
		return sum;
}

public int chords(int n) {
		if(n == 0)
				return 1;
		int[] table = new int[n + 1];
		table[0] = 1;
		table[1] = 1;
		for(int i = 2; i <= n; i++) {
				for(int j = 0; j < i; j++) {
						table[i] += table[j] * table[i - 1 - j];
				}
		}
		return table[n];
}
