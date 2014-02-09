/*
Implementation of Advanced set which have the functionality as "Set" in c++ along with extra functionality-Random number generator.Returns the random number from the set.
*/

typedef struct node {
		int data, size;
		node *left, *right;
} node;

node * generateRandomNode(node * root, int k) {
		if (!root || root->size < k)
				return NULL;
		int lsize = 0;
		if (!root->left) {
				lsize = root->left->size;
		}
		if (lsize >= k)
				return getRandomNode(root->left , k);
		else if (lsize + 1 == k)
				return root;
		else
				return getRandomNode(root->right, k - lsize - 1);
}

node * generateRandomNode(node *root) {
		if (!root)
				return NULL;
		int k = rand(root->size) + 1;
		return getRandomNode(root, k);
}
