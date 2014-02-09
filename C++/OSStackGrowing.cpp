# include <iostream>

using namespace std;

void foo(int * a) {
		int b = 2;
		if (a - &b > 0)
				cout << "Growing Down (" << a << " - " << &b << ")" << endl;
		else
				cout << "Growing Up (" << a << " - " << &b << ")" << endl;
}

int main(int argc, char * const argv[]) {
		int a = 1;
		foo(&a);
		return 0;
}
