/*
    delete a node in the binary search tree
*/
node* delete_node(node* root, int data)
{
    if(root == NULL)
        return NULL;
 
    node *cursor;
    if(data < root->data)
        root->left = delete_node(root->left, data);
    else if(data > root->data)
        root->right = delete_node(root->right,data);
    else
    {
        if (root->left == NULL)
        {
            cursor = root->right;
            free(root);
            root = cursor;
        }
        else if (root->right == NULL)
        {
            cursor = root->left;
            free(root);
            root = cursor;
        }
        else    //2 children
        {
            cursor = root->right;
            node *parent = NULL;
 
            while(cursor->left != NULL)
            {
                parent = cursor;
                cursor = cursor->left;
            }
            root->data = cursor->data;
            if (parent != NULL)
                parent->left = delete_node(parent->left, parent->left->data);
            else
                root->right = delete_node(root->right, root->right->data);
        }
    }
    return root;
}
