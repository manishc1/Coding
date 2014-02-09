/*
Given an 8x8 chess board, you have a bishop that moves from the current to the target position. write a code to find the minimum path from the current to the target position.
*/

# include <stdio.h>

void move(int* a) {
		if (*a - 1 >= 0)
				(*a)--;
		else
				(*a)++;		
}

void printPath(int x, int y, int endx, int endy) {
		printf("%d, %d\n", x, y);
		if ((x == endx) && (y == endy))
				return;
		if (x == endx) {				
				if (y < endy) {
						y++;
						move(&x);
				} else {
						y--;
						move(&x);
				}
		} else if (x < endx) {
				x++;
				if (y < endy)
						y++;
				else if (y > endy)
						y--;
				else
						move(&y);
		} else {
				x--;
				if (y < endy)
						y++;
				else if (y > endy)
						y--;
				else
						move(&y);
		}
		printPath(x, y, endx, endy);
}
void main() {
		int startx=0, starty=0, endx=7, endy=2;
		if ((startx + starty + endx + endy) & 1)
				printf("No Path exists");
		else
				printPath(startx, starty, endx, endy);
}
