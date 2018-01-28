#include <iostream>

typedef struct Node{
    int data;
    struct Node * left;
    struct Node * right;
    struct Node * root;
    
    
}Node;


Node * append ( Node * root, int data){
    
    if (root == NULL){
        root = new Node();
        root->l = NULL;
        root->root = NULL;
        root->r = NULL;
        root->data = data;
        return root;
    }
    
    else {
        
        Node *prtR = root;
        while (prtR->r != NULL && prtR->l !=NULL)
        {
            if (prtR->data<data)
                prtR= prtR->r;
            else if (prtR->data > data)
                prtR= prtR->l;
        }
        if (prtR->r==NULL && prtR->data < data)
        {
            prtR->r = new Node();
            prtR->r->data = data;
            prtR->r->l = NULL;
            prtR->r->r = NULL;
            prtR->r->root = prtR;
        }
        else if (prtR->l == NULL && prtR->data>data)
        {
            prtR->l = new Node();
            prtR->l->data = data;
            prtR->l->l = NULL;
            prtR->l->r = NULL;
            prtR->l->root = prtR;
        }
        
        return root;
        
    }
    
    
}
void topView(Node* root){
	
	Node *prtR = root;
	if (root == NULL)
		return;
	else {
		if (prtR->right != NULL)
		{
			printf("%d ",prtR->data);
			topView(prtR->R);
		}
		
	}
	
}



int main(){
    Node * head = NULL;
    head = append(head, 10);
    head = append(head, 15);
    head = append(head, 5);
    head = append(head, 16);
    head = append(head, 6);
    head = append(head, 14);
    head = append(head, 4);



    return 0;
}
