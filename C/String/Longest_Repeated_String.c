/*
Write a program to return the longest repeating 
substring in a string. eg. for "ababab", "abab" is the longest repeating substring.
*/

static string FindLongestRepeationgSubstring(string s)
{
	int n = s.length();
	int pi[n][n];
	for (int i = 0; i < n; ++i)
		pi[i][i] = i - 1;
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int k = pi[i][j-1];
			while (k >= i && s[j] != s[k+1]) k = pi[i][k];
			
			if (s[j] == s[k+1]) k++;
			
			pi[i][j] = k;
		}
	}
	
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = i; j < n; ++j)
		{
			cout << pi[i][j] << " ";
		}
		cout << endl;
	}
	
	int ls = -1;
	int le = -1;
	int l = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			int tempL = pi[i][j] - i + 1;
			if ((pi[i][j] >= j - tempL) && tempL > l)
			{
				l = tempL;
				ls = i;
				le = pi[i][j];
			}
		}
	}
	
	if (l > 0)
		return s.substr(ls, l);
	else
		return "";
}
