// practice.cpp : Defines the entry point for the console application.
//

#include<iostream>

using namespace std;


void combination(int n,int i,int k);


void display(int * arr,int n)
{
	cout<<"{";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i];
	    if(i<n-1) cout<<",";
	}
	cout<<"}";
	cout<<endl;
}



int main( )
{
	int n=0;
	cout<<"Enter The Number::";
	cin>>n;
	
	
    combination(n,0,n-1);

	return(0);
}


void combination(int n,int i,int kk)
{
 static int * arr=new int [kk];
  if (n == 0)
  {
    display(arr, i);
  }
  else if(n > 0)
  {
    int k; 
    for (k = 1; k <= kk; k++)
    {
      arr[i]= k;
      combination(n-k, i+1,k);
    }
  }
}
