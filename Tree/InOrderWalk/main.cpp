#include <iostream>

typedef struct node{
    int data;
    struct node * l;
    struct node * r;
    struct node * root;
    
    
}node;


node * append ( node * root, int data){
    
    if (root == NULL){
        root = new node();
        root->l = NULL;
        root->root = NULL;
        root->r = NULL;
        root->data = data;
        return root;
    }
    
    else {
        
        node *prtR = root;
        while (prtR->r != NULL && prtR->l !=NULL)
        {
            if (prtR->data<data)
                prtR= prtR->r;
            else if (prtR->data > data)
                prtR= prtR->l;
        }
        if (prtR->r==NULL && prtR->data < data)
        {
            prtR->r = new node();
            prtR->r->data = data;
            prtR->r->l = NULL;
            prtR->r->r = NULL;
            prtR->r->root = prtR;
        }
        else if (prtR->l == NULL && prtR->data>data)
        {
            prtR->l = new node();
            prtR->l->data = data;
            prtR->l->l = NULL;
            prtR->l->r = NULL;
            prtR->l->root = prtR;
        }
        
        return root;
        
    }
    
    
}

void inOrderWalk(node *root){
	
	if (root==NULL)
		return ;
	
	else {
		node *prtR = root;
	//	while (prtR->l != NULL && prtR->r != NULL){
		inOrderWalk(prtR->l);
		printf("%d\n", prtR->data);
		inOrderWalk(prtR->r);
		//}

		
	}

	
}

void priorOrderWalk(node *root){
	
	if (root==NULL)
		return ;
	
	else {
		node *prtR = root;
		printf("%d\n", prtR->data);
		inOrderWalk(prtR->l);
		inOrderWalk(prtR->r);


		
	}

	
}


void postOrderWalk(node *root){
	
	if (root==NULL)
		return ;
	
	else {
		node *prtR = root;

		inOrderWalk(prtR->l);
		inOrderWalk(prtR->r);
		printf("%d\n", prtR->data);
		
	}

	
}



int main(){
    node * head = NULL;
    head = append(head, 10);
    head = append(head, 15);
    head = append(head, 5);
    head = append(head, 16);
    head = append(head, 6);
    head = append(head, 14);
    head = append(head, 4);
	printf("inOrder\n");
    inOrderWalk(head);
	printf("priorOrder\n");
	priorOrderWalk(head);
	printf("postOrder\n");
	postOrderWalk(head);
    return 0;
}
