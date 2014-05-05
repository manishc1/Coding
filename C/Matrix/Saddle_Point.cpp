/*Given an NxN matrix with unique integers : Find and print positions of all numbers such that it is the biggest in its row and also the smallest in its collumn . 

eg : In 3 x 3 with elements 

1 2 3 
4 5 6 
7 8 9 

the number is 3 and position (2,2)*/

# include <iostream>
# include <climits>

using namespace std;

class Matrix {
private:
		int matrix[3][3];
public:
		Matrix();
		void findSaddlePoints();
};

Matrix :: Matrix() {
		matrix[0][0] = 7;
		matrix[0][1] = 2;
		matrix[0][2] = 1;
		matrix[1][0] = 4;
		matrix[1][1] = 5;
		matrix[1][2] = 6;
		matrix[2][0] = 3;
		matrix[2][1] = 8;
		matrix[2][2] = 9;
}

void Matrix :: findSaddlePoints() {
		int i, j;
		int maxOfRow[3] = {0};
		int minOfCol[3] = {0};

		for(i=0; i<3; i++) {
				for(j=0; j<3; j++){
						if(matrix[i][maxOfRow[i]] < matrix[i][j])
								maxOfRow[i] = j;
						if(matrix[minOfCol[i]][j] > matrix[i][j])
								minOfCol[j] = i;
				}
		}

		for(i=0; i<3; i++) {
				if(minOfCol[maxOfRow[i]] == i)
						cout << "matrix[" << minOfCol[maxOfRow[i]] << "][" << maxOfRow[i] << "] = " << matrix[minOfCol[maxOfRow[i]]][maxOfRow[i]]<< endl;
		}
}

int main() {
		Matrix m;
		m.findSaddlePoints();
		return(0);
}
