
void topView(node * root)
{
    node *prtR = root;
    if (root == NULL) return;
    else {
        
        vector <node*> vL;
        vector <node*> vR;
        
        while (prtR->left!=NULL)
        {
            vL.push_back(prtR->left);
            prtR = prtR->left;
        }
        prtR = root;
       while (prtR->right!=NULL)
        {
            vR.push_back(prtR->right);
            prtR = prtR->right;
        }
        for (int i=vL.size()-1; i>=0; i--)
            printf("%d ", vL[i]->data);
        
        printf("%d ", root->data);
        
        for (int i=0 ;i<vR.size(); i++)
            printf("%d ", vR[i]->data); 
    }
}

