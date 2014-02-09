# include <stdio.h>
# include <string.h>

#define DELETE_COST 1
#define INSERT_COST 1
#define CHANGE_COST 1

int min(int x, int y, int z) {
		if (x<=y && x<=z)
				return x;
		if (y<=z && y<=x)
				return y;
		if (z<=x && z<=y)
				return z;
}

int findEditDistance(char* old, int i, char* new, int j) {
		int ch;
		if ((i == -1) && (j == -1))
				return 0;
		if (i == -1)
				return (j+1)*DELETE_COST;
		if (j == -1)
				return (i+1)*INSERT_COST;
		ch = (old[i]==new[j]) ? 0 : CHANGE_COST;
		return min(DELETE_COST + findEditDistance(old, i, new, j-1),
				   INSERT_COST + findEditDistance(old, i-1, new, j),
				   ch + findEditDistance(old, i-1, new, j-1));
}

void main() {
		char old[10] = "ccat1";
		char new[10] = "bbbat2";
		int distance;
		distance = findEditDistance(old, strlen(old)-1, new, strlen(new)-1);
		printf("Distance : %d\n", distance);
}
