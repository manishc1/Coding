/*
Flip a monochrome bitmap around its centre-line, where input is: char *bytes, int width, int height . 

Example: 
Input 
0101 0110 
1111 0011 

Output 
0110 1010 
1100 1111
*/

void swap(char *x, char *y) {
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
}

void flipbyte(char *x) {
	int i, j, allone = ~(0);
	for (i=0,j=7; i<j; i++,j--) {
		imask = ~(allone << (i+1);
		jmask = allone << j;
		ibit = *x & imask;
		jbit = *x & jmask;
		*x = (*x | 1<<i) & (jbit<<i);
		*x = (*x | 1<<j) & (ibit<<j);
	}
}

	// Better n Neat
void flipbyte(char* b) {
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
}

void flip(char *bytes, int width, int height) {
	int i, j;

	for (i=0; i<height; i++) {
		for (j=0; j<width/2; j++) {
			swap(&byte[i][j],&byte[i][width-1-j])
		}
	}

	for (i=0; i<height; i++) {
		for (j=0; j<width; j++) {
			flipbyte(&byte[i][j]);
		}
	}
}
