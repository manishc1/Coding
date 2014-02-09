/*
A binary tree is given with left and right populated but the nextRight pointers in each node are not populated. Populate the nextRight pointer in each node.
*/

void setInorderSuccessorPointer(node* root, node* potentialSuccessor) {
		if(root == NULL)
				return;
		node* ptr = root->right;
		if(ptr != NULL) {
				while(ptr->left != NULL)
						ptr = ptr->left;
				root->inorderSuccessor = ptr;						
		} else {
				root->inorderSuccessor = potentialSuccessor;
		}

		setInorderSuccessorPointer(root->left, root);
		setInorderSuccessorPointer(root->right, NULL);
}
