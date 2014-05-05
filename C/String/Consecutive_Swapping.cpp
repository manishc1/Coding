/* Given two strings , find the way to reach from one to other using consecutive swapping only */

# include <iostream>

# define MAX 10

using namespace std;

class Strings {
private:
		char str1[MAX], str2[MAX];
		void swapChar(char*, char*);
		void swapInt(int*, int*);
public:
		Strings();
		void consecSwap();
};

Strings :: Strings() {
		str1[0]='m';str1[1]='u';str1[2]='g';str1[3]='\0';
		str2[0]='g';str2[1]='u';str2[2]='m';str2[3]='\0';
}

void Strings :: swapChar(char* x, char* y) {
		char s;
		s = *x;
		*x = *y;
		*y = s;
}

void Strings :: swapInt(int* x, int* y) {
		int s;
		s = *x;
		*x = *y;
		*y = s;
}

void Strings :: consecSwap() {		
		int i, j, hash[256] = {-1};
		for(i=0 ; str1[i]!='\0' ; i++)
				hash[str1[i]] = i;
	    for(j=0 ; str2[j]!='\0' ; j++) {
				i = hash[str2[j]];
				while(i!=j) {
						swapChar(&str1[i], &str1[i-1]);
						swapInt(&hash[str1[i]], &hash[str1[i-1]]);
						i--;
						cout<< str1 << endl;
				}
		}
		cout<< "Str1 : " << str1 << " Str2 : " << str2 << endl;		
}

int main() {
		Strings s;
		s.consecSwap();
		return(0);
}
