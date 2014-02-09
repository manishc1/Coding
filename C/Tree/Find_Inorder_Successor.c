/*
Given a BST and a node, write the BST data structure and a method in Java

Node findNode(Node n)

that will find the next node of n in the BST. For example, if the tree looks like:
     7
    / \
   5  11
  / \ /
 4  6 9 
/ \
2 15

Then, 
findNode(2) = 4, 
findNode(4) = 5, 
findNode(5) = 6
findNode(6)=7
findNode(7)=9
findNode(9)=11
findNode(11)=15

Note that you are not given the root of the tree.

Hint: you may assume that you have parent pointer.
*/

treenode * findnextnode(treenode *node) {
		treenode *p;
		if (node->right != NULL) {
				p = node->right;
				while(p->left != NULL)
						p = p->left;
				return p;
		}
		else {
				p = node;
				while ((p->parent->left != p) && (p->parent != NULL))
						p = p->parent;
				return p->parent;
		}
}
