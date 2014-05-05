void MorrisInorder(NODE *root) {
    NODE* current,*pre;
    current=root;
    while(current!=NULL) {
        if(current->left==NULL) {
            printf("%d ",current->data);
            current=current->right;
        }
        else {
            pre=current->left;
            while(pre->right != NULL && pre->right !=current) 
                pre=pre->right;
            if(pre->right==NULL) {
                pre->right=current;
                current=current->left;
            }
            else {
                pre->right=NULL;
                printf("%d ",current->data);
                current=current->right;
            }
        }
    }
}
