node * construct (int *a, int n) {
		int i, m;
		node *root = NULL;

		m = 1;
		root = getNode(a[0]);
		for (i=1 ; i<n ; i++)
				if (a[i] > a[0])
						break;

		if (i > m)
				root->left = construct(&a[m], i);
		else
				root->left = NULL;

		if (n > i)
				root->right = construct(&a[i], n-i);
		else
				root->right = NULL;

		return root;
}
