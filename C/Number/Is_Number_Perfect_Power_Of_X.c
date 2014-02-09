# include <stdio.h>
# include <math.h>

void main() {
		float N[] = {1,2,3,4,5,6,7,8};
		float X = 2;
		int i;
		float power;
		for(i=0 ; i<8 ; i++) {
				power = log(N[i])/log(X);
				if(power == (int)power)
						printf("%f is     a perfect power\n", N[i]);
				else
						printf("%f is NOT a perfect power\n", N[i]);
		}
}
