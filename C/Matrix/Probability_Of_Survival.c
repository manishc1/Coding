/*
There is an island which is represented by square matrix NxN. 
A person on the island is standing at any given co-ordinates (x,y). He can move in any direction one step right, left, up, down on the island. If he steps outside the island, he dies. 

Let island is represented as (0,0) to (N-1,N-1) (i.e NxN matrix) & person is standing at given co-ordinates (x,y). He is allowed to move n steps on the island (along the matrix). What is the probability that he is alive after he walks n steps on the island? 

Write a psuedocode & then full code for function 
" float probabilityofalive(int x,int y, int n) ".
*/

# include <stdio.h>

# define N 4

int isInvalid(int a) {
		if(a<0 || a>=N)
				return 1;
		return 0;
}
float probabilityofalive(int x, int y, int steps) {
		if(isInvalid(x) || isInvalid(y))
				return 0;
		if(steps==0)
				return 1;
		return(probabilityofalive(x+1, y  , steps-1) +
			   probabilityofalive(x  , y+1, steps-1) +
			   probabilityofalive(x-1, y  , steps-1) +
			   probabilityofalive(x  , y-1, steps-1))/4;
}

void main() {
		int x = 2, y = 2;
		int steps = 20;
		printf("%f\n", probabilityofalive(x, y, steps));
}
