/*
Write a function to determine node in a tree at maximum depth , with ties to the right ( ties to the right means , right most node at MaxDepth D )
*/
void findRightMostHelper (Node* p, int& maxDepth, Node*& rNode, int depth){
  if (p == NULL) return;
  if (depth >= maxDepth){
    maxDepth = depth;
    rNode = p;
  }
  findRightMostHelper(p->left, maxDepth, rNode, depth+1);
  findRightMostHelper(p->right, maxDepth, rNode, depth+1);
}

void main() {
		Node *root, *rNode;
		int maxDepth = 0;		
		findRightMostHelper(root, &maxDepth, rNode, 0);
}
