# include <iostream>

using namespace std;

class node {

private:
		int val;
		node *left, *right;
		node *prev, *next;

public:
		void node(int x) {
				val = x;
				left = right = NULL;
		}

		void setData() {
				val = 1;
		}
};

class tree {

private:	   
		node *root;

public:
		void print();
		void create();
};

void tree::setNode() {
		
		root->setData(1);
}

void tree::print() {
		cout << getData()
}

int main(int argc, char * const argv[]) {
		tree t;
		t.create();
		t.print();

		return 1;
}
