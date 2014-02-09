/*
5
|  \
2   1
|\   \
3 7   8

In
3 2 7 | 5 | 1 8

Pre
5 2 3 7 1 8

5: 3 2 7, 1 8
2: 3, 7, 1 8
3: 7, 1 8
7: 1 8
1: 

5  LLetfRRight 

(2 

strleft (3()())   strright (7()()))     


(1()(8()())))
*/

node * build (char * str) {
    node * root;
    int val,leftend;
    char * strleft = NULL;
    char * strright = NULL;
    root = getNode();
    
    if(strlen(str) == 2)
        return NULL;
        
    val = (int)str[1];
    leftend = getstr(&str[2],strleft);
    getstr(&str[leftend+1] , strright);
    
    root->data = val;
    root->left = build(strleft);
    root->right = build(strright);

    return root;
}
