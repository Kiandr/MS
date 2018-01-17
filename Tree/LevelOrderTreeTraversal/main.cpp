#include <iostream>

typedef struct Node{
    int data;
    struct Node * l;
    struct Node * r;
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

void inOrderWalk(Node *root){
    if (root==NULL)
        return ;
    else {
        Node *prtR = root;
        inOrderWalk(prtR->l);
        printf("%d\n", prtR->data);
        inOrderWalk(prtR->r);
    }
}

void priorOrderWalk(Node *root){
    
    if (root==NULL)
        return ;
    else {
        Node *prtR = root;
        printf("%d\n", prtR->data);
        inOrderWalk(prtR->l);
        inOrderWalk(prtR->r);
    }
}


void postOrderWalk(Node *root){
    
    if (root==NULL)
        return ;
    
    else {
        Node *prtR = root;
        
        inOrderWalk(prtR->l);
        inOrderWalk(prtR->r);
        printf("%d\n", prtR->data);
        
    }
    
    
}


int height(Node* root) {
    // Write your code here.
    if (root->r==NULL && root->l==NULL)
        return 0;
    
    int lH = 0, rH = 0;
    Node * prtR = root;
    if (prtR->l)
        lH = height(prtR->l);
    if (prtR->r)
        rH = height(prtR->r);
    
    if (rH>lH)
        return rH+1;
    return lH+1;
    
    //    return 1 + max(hL, hR);
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
    printf("inOrder\n");
    inOrderWalk(head);
    printf("priorOrder\n");
    priorOrderWalk(head);
    printf("postOrder\n");
    postOrderWalk(head);
    return 0;
}

