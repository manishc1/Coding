/*
Given a function KNOWS(A,B), which returns 1 if A knows B (and not necessarily the other way around) and 0 if A does not know B. 

A Celebrity is one who does not know anyone, 
and one who is known by everybody. 

For a list of N people, find all celebrities in linear time.
*/

//a[i][j] =1 denotes person i know person j
int Celebrity(vector<vector<int> >& a)
{
	int candidate=0;
	int i=1;
	while(i < a.size())
	{
		if(!a[i][candidate] || a[candidate][i])
			candidate=i;
		i++;
	}
	//check
	for(int i=0;i<a.size();i++)
	{
		if(i!=candidate && (!a[i][candidate] || a[candidate][i]))
		return -1;//no celebrity exist
	}
	return candidate;
}
