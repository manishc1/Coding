/*Substring Addition 
Write a program to add the substring 
eg :say you have a list {1 7 6 3 5 8 9 } and user is entering a sum 16.Output should display (2-4) that is {7 6 3} cause 7+6+3=16.*/

# include <iostream>

using namespace std;

class Set {
private:
		int set[10], len;
public:
		Set();
		void findSubSetOfSum(int);
};

Set :: Set() {
		set[0]=1;set[1]=7;set[2]=6;set[3]=3;set[4]=5;set[5]=8;set[6]=9;
		len = 7;
}

void Set :: findSubSetOfSum(int sum) {
		int i, j, currSum;
		i=j=0;
		currSum = set[0];
		while(i<len && j<len) {
				if(currSum == sum) {
						cout << i+1 << " - " << j+1 << endl;
						return;
				}
				if(currSum < sum) {
						j++;
						if (j<len)
								currSum += set[j];
						else
								return;
				} else {
						if (i == j) {
								i = j = i+1;
								currSum = set[i];
						} else {
								currSum -= set[i];
								i++;
						}
				}
		}
		cout << "No subset" << endl;
}

int main() {
		Set s;
		s.findSubSetOfSum(9);
		return(0);
}
