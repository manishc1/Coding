/*
Given a number check whether it is equal to its sum of its factors or not (excluding the number itself)
*/

# include <iostream>

using namespace std;

class Number {
private:
		int num;
public:
		Number();
		int isSumOfFactorsEqualToNumber();
};

Number :: Number() {
		num = 12;
}

int Number :: isSumOfFactorsEqualToNumber() {
		unsigned int i, sum = 0;;

		for(i=1 ; i*i<=num ; i++) {
				if(num%i == 0) {
						sum += i;
						if(i != num/i)
								sum += (num/i);
				}
		}
		return(sum == 2*num);
}

int main() {
		Number n;
		if(n.isSumOfFactorsEqualToNumber())
				cout << "Yes" << endl;
		else
				cout << "No" << endl;
		return(0);
}
