/* check i = 2^k */

/*
if (!(n&(n-1)))
printf("power of 2");

*/

#include <stdio.h>

void main(){
		int i, j=0, count=0;
		printf("\nNumber :: ");
		scanf("%d",&i);
		//printf("%d",i&~(0x0));
		
		while(i & ~(0x0)){
				if(i&0x1) count++;
				i = i>>1;
		}

		/*
		if (n==0 || n&(n-1)==0) it is power of 2.
		*/

		if (count <= 1) printf("Yes\n");
		else printf("No\n");
}
