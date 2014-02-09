node * LCA (node *root, int a, int b) {
		if (root == NULL || root->data == a || root->data == b)
				return root;

		node *L = LCA (root->left, a, b);
		node *R = LCA (root->right, a, b);
		if (L != NULL && R != NULL)
				return root;
		else if (L != NULL)
				return L->left;
		else if (R != NULL)
				return L->right;
		return NULL;
}
