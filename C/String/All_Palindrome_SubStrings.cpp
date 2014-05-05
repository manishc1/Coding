/*Print all palindromes of size greater than equal to 3 of a given string.*/

# include <iostream>
# include <string.h>
# include <math.h>

# define MAX 100

using namespace std;

class Strings {
private:
		char str[MAX];
		int minPalSize;
		void printString(int, int);
		void isPalindrome(int, int);
		void findAllPalindromesHelper(float);
public:
		Strings();
		void findAllPalindromes();
};

Strings :: Strings() {
		strcpy(str, "aabbaa");
		minPalSize = 3;
}

void Strings :: printString(int start, int end) {
		while(start<=end) {
				cout << str[start++];						
		}
		cout << endl;
}

void Strings :: isPalindrome(int start, int end) {
		if((start >= 0) && (end < strlen(str)) && (str[start] == str[end])) {
				if(end - start + 1 >= minPalSize)
						printString(start, end);
				isPalindrome(start-1, end+1);
		}
}

void Strings :: findAllPalindromesHelper(float mid) {
		if (mid >= strlen(str))
				return;
		isPalindrome((int)floor(mid), (int)ceil(mid));
		findAllPalindromesHelper(mid + 0.5);
}

void Strings :: findAllPalindromes() {
		findAllPalindromesHelper(0);
}

int main() {
		Strings s;
		s.findAllPalindromes();
		return(0);
}
