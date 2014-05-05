/*Given a integer, which is the length of a string containing numbers, give a complete permutation of strictly increasing numbers*/

# include <iostream>

using namespace std;

class Numbers {
private:
		int size;
		void printNumbersHelper(char*, int, int);
public:
		Numbers();
		void printNumbers();
};

Numbers :: Numbers() {
		size = 3;
}

void Numbers :: printNumbersHelper(char* num, int index, int prev) {
		int i;
		if (index == size) {
				cout << num << endl;
				return;
		}
		for (i=prev+1 ; i<5 ; i++) {
				num[index] = i + '0';
				printNumbersHelper(num, index+1, i);
		}
}

void Numbers :: printNumbers() {
		char num[10] = {'\0'};
		printNumbersHelper(num, 0, 0);
}

int main() {
		Numbers n;
		n.printNumbers();
		return(0);
}
