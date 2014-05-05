# include <functional>
# include <iostream>
# include <string>
# include <vector>

using namespace std;

class Number {
private:
		int n;
public:
		Number();
		int isColourful();
};

Number :: Number() {
		n = 263;
}

int Number :: isColourful() {
		std::vector<int> digits;
		int len=0, digit, i;
		std::hash<std::string> digitHash;
		string s;
		while(n>0) {
				digit = n%10;
				n = n/10;
				len++;
				if (digit==0 || digit==1 || len>10)
						return(0);
				for(i=digits.size()-1; i>=0; i--) {
						s = std::to_string(digit*digits.at(i));
						if(digitHash(s) != NULL)
								return(0);
						digitHash(s) = 1;
						digits.push_back(digit*digits.at(i));						
				}
				cout<<digitHash(digit);
				s = std::to_string(digit);
				if (digitHash(s) != NULL)
						return(0);
				digitHash(s) = 1;
				digits.push_back(digit);
		}
		return(1);
}

int main() {
		Number n;
		if(n.isColourful())
				cout<<"Yes"<<endl;
		else
				cout<<"No"<<endl;
		return(0);
}
