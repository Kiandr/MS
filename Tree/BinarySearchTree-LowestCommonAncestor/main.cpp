/*
Node is defined as 

typedef struct node
{
   int data;
   node *left;
   node *right;
}node;

*/

// recursion 
node *lca(node *root, int v1,int v2)
{

        node *prtR = root;
    if (root == NULL) return NULL;

    else {
        if (prtR->data<v1 &&  prtR->data<v2 )
            prtR = lca(prtR->right, v1,v2);
        if (prtR->data>v1 && prtR->data > v2) 
            prtR = lca(prtR->left, v1,v2);
    }
    return prtR;
}

// Non recursion
node *lca(node *root, int v1,int v2)
{

    node *prtR = root;
    while (prtR!=NULL){
    if (root == NULL) return NULL;

    else {
        if (prtR->data<v1 &&  prtR->data<v2 )
//            prtR = lca(prtR->right, v1,v2);
            prtR = prtR->right;
       else if (prtR->data>v1 && prtR->data > v2) 
  //          prtR = lca(prtR->left, v1,v2);
            prtR = prtR->left;
        else return prtR;
		}
    }
    return prtR;
}

