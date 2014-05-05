/* Find the k'th largest element in a binary search tree. Write code for */

# include <stdio.h>
# include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

Node* getNode(int x) {
		Node* p;
		p = (Node*)malloc(sizeof(Node*));
		p->val = x;
		p->left=p->right=NULL;
		return p;
}

Node* createTree(Node* root) {
		root = getNode(4);
		root->left = getNode(2);
		root->right = getNode(6);
		root->left->left = getNode(1);
		root->left->right = getNode(3);
		root->right->left = getNode(5);
		root->right->right = getNode(7);
		return root;
}

Node* kth_largest(Node *root, unsigned int k) {
		static int i = 0;
		Node* r;

		if(root == NULL)
				return NULL;

		r = kth_largest(root->right, k);
		if (r != NULL)
				return r;

		i++;
		if(k == i)
				return root;

		return kth_largest(root->left, k);
}

void main() {
		Node* root = NULL, *p;
		root = createTree(root);
		p = kth_largest(root, 3);
		if(p)
				printf("%d\n", p->val);
		else
				printf("No\n");
}
