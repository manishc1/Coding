# include <stdio.h>

# define N 40

char mat[N][N];

void MidPoint(int x0, int y0, int radius) {
		int x = radius, y = 0;
		int radiusError = 1-x;
		char c = 'o';

		while(x >= y) {
				mat[x0+x][y0+y] = c; //DrawPixel(x + x0, y + y0);
				mat[x0+y][y0+x] = c; //DrawPixel(y + x0, x + y0);
				mat[x0-x][y0+y] = c; //DrawPixel(-x + x0, y + y0);
				mat[x0-y][y0+x] = c; //DrawPixel(-y + x0, x + y0);
				mat[x0-x][y0-y] = c; //DrawPixel(-x + x0, -y + y0);
				mat[x0-y][y0-x] = c; //DrawPixel(-y + x0, -x + y0);
				mat[x0+x][y0-y] = c; //DrawPixel(x + x0, -y + y0);
				mat[x0+y][y0-x] = c; //DrawPixel(y + x0, -x + y0);
				y++;
				if (radiusError<0) {
						radiusError += 2 * y + 1;
				} else {
						x--;
						radiusError+= 2 * (y - x + 1);
				}
		}
}

void init() {
		int i, j;
		for (i=0 ; i<N ; i++)
				for (j=0 ; j<N ; j++)
						mat[i][j] = '.';
}

void print() {
		int i, j;
		for (i=0 ; i<N ; i++) {
				for (j=0 ; j<N ; j++)
						printf("%c ", mat[i][j]);
				printf("\n");				
		}
		printf("\n");
}

void main() {
		init();
		//print();
		MidPoint(N/2, N/2, N/2-2);
		print();
}
