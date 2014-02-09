#include <stdio.h>

void main() {
		int x=2, y=6, z=5;
		int t=1;
		int i;
		for(i=0; i<y; i++) {
				t = (t*x)%z;
		}
		printf("%d\n", t);
}
