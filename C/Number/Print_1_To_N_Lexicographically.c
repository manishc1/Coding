void lexic_1_to_N(int N, int k)  {
	if (k > N)
		return;

	for(int i = 0; i<10; i++)  { 
		if (k <= N)  { 
			cout<<k<<endl; 
			k *= 10; 
			lexic_1_to_N(N, k); 
			k /= 10; 
			k++; 
			if (k%10 == 0)
				return; 
		} 
	} 
}
