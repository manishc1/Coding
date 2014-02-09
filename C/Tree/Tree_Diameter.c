/*
Definition: The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two leaves in the tree.

The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).

Diag : http://tech-queries.blogspot.com/2010/09/diameter-of-tree-in-on.html

It can be shown that the diameter of a tree T is the largest of the following quantities:

the diameter of T's left subtree
the diameter of T's right subtree
the longest path between leaves that goes through the root of T (this can be computed from the heights of the subtrees of T)
*/

int diameter2(TreeNode t, int* height)
{
    int lh = 0, rh = 0;
    int leftD = 0, rightD = 0;
 
    if(t == NULL)
    {
        *height = 0;
        return 0; /* diameter is also 0 */
    }
 
    leftD = diameter2(root->left, &lh);
    rightD = diameter2(root->right,&rh);
 
    /* Height of current node is max of heights of left and
    right subtrees plus 1*/
    *height = max(lh, rh) + 1;
 
    return max(lh + rh + 1, leftD, rightD);
}
