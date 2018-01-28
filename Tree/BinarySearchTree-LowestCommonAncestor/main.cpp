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

/*
	Failed on this:
8
8 4 9 1 2 3 6 5
1 2
	
*/
node *lca(node *root, int a,int b)
{
	if (root == NULL) return NULL;
	else {
		node *prtR = root;
		
		while (prtR!=NULL)
		{
			if (prtR->data >a && prtR->data>b && prtR->left !=NULL)
				prtR = prtR->left;
			else if (prtR->data <a && prtR->data<b && prtR->right !=NULL)
				prtR = prtR->right;
			else return prtR;
			
		}
	}
	return root;
}
		
		

	
	



// PASSED THIS
node *lca(node *root, int a,int b)
{
    node *prtR = root;
	if (root == NULL) return NULL;
	else {		
		if (prtR!=NULL)
		{
			if (prtR->data >a && prtR-> data>b )
				prtR = lca (prtR->left,a,b);
			if (prtR->data <a && prtR->data<b )
				prtR = lca (prtR->right,a,b);
		}
	}
	return prtR;
}



