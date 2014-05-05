//Find the minimum depth of a binary tree

int min_depth(struct Node* root, int depth)
{
	if (root->left == NULL && root->right == NULL)
		return depth;

	int x = (root->left != NULL) ? min_depth(root->left, depth+1) : depth;
	int y = (root->right != NULL) ? min_depth(root->right, depth+1) : depth;

	return (x < y) ? x : y;
}
