/* find first missing number in sorted array in O(log n)*/

#include <stdio.h>

int find(int a[], int n) {
		int l=0, u=n-1, m;
		if (n<1)
				return -1;
		
		while(l<u) {
				if(l+1 == u) {
						if(a[l]+1 == a[u])
								return(a[n-1]+1);
						else
								return(a[l]+1);
				}
				m = (l+u)/2;
				if((m-l) == (a[m]-a[l]))
						l = m;
				else
						u = m;						   
		}
		return a[n-1]+1;
}

void main() {
		int a[9] = {4,5,6,7,9,11,14,18,19};
		printf("%d\n",find(a,9));
}
