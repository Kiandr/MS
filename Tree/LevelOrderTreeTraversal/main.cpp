#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

typedef struct Node{
    int data;
    struct Node * left;
    struct Node * right;
    struct Node * root;
    
    
}Node;


Node * append ( Node * root, int data){
    
    if (root == NULL){
        root = new Node();
        root->left = NULL;
        root->root = NULL;
        root->right = NULL;
        root->data = data;
        return root;
    }
    
    else {
        
        Node *prtR = root;
        while (prtR->right != NULL && prtR->left !=NULL)
        {
            if (prtR->data<data)
                prtR= prtR->right;
            else if (prtR->data > data)
                prtR= prtR->left;
        }
        if (prtR->right==NULL && prtR->data < data)
        {
            prtR->right = new Node();
            prtR->right->data = data;
            prtR->right->left = NULL;
            prtR->right->right = NULL;
            prtR->right->root = prtR;
        }
        else if (prtR->left == NULL && prtR->data>data)
        {
            prtR->left = new Node();
            prtR->left->data = data;
            prtR->left->left = NULL;
            prtR->left->right = NULL;
            prtR->left->root = prtR;
        }
        return root;
    }
}

void inOrderWalk(Node *root){
    if (root==NULL)
        return ;
    else {
        Node *prtR = root;
        inOrderWalk(prtR->left);
        printf("%d\n", prtR->data);
        inOrderWalk(prtR->right);
    }
}

void priorOrderWalk(Node *root){
    
    if (root==NULL)
        return ;
    else {
        Node *prtR = root;
        printf("%d\n", prtR->data);
        inOrderWalk(prtR->left);
        inOrderWalk(prtR->right);
    }
}


void postOrderWalk(Node *root){
    
    if (root==NULL)
        return ;
    
    else {
        Node *prtR = root;
        
        inOrderWalk(prtR->left);
        inOrderWalk(prtR->right);
        printf("%d\n", prtR->data);
        
    }
    
    
}


int height(Node* root) {
    // Write your code here.
    if (root->right==NULL && root->left==NULL)
        return 0;
    
    int lH = 0, rH = 0;
    Node * prtR = root;
    if (prtR->left)
        lH = height(prtR->left);
    if (prtR->right)
        rH = height(prtR->right);
    
    if (rH>lH)
        return rH+1;
    return lH+1;
    
    //    return 1 + max(hL, hR);
}




void levelOrder(Node* root)
{
    queue<Node*> q;
    if (root) q.push(root);
    for (; !q.empty(); q.pop())
    {
        cout<<q.front()->data<<' ';
        if (q.front()->left) q.push(q.front()->left);
        if (q.front()->right) q.push(q.front()->right);
    }
}


void levelOrder2(Node *root){
    queue <Node*>q;
    if (root == NULL)
        return;
    else {
        q.push(root);
        while (!q.empty()){
            printf("%d ", q.front()->data);
            if (q.front()->left != NULL)
                q.push(q.front()->left);
            if (q.front()->right != NULL)
                q.push(q.front()->right);
            q.pop();
        }
    }
    
}



void levelOrder3(Node * root)
{
    Node * nodeList[10000];
    int n = 1;
    int i = 0;
    
    nodeList[0] = root;
    
    while (i < n) {
        Node *prtN = nodeList[i];
        if (prtN->left) {
            nodeList[n++] = prtN->left;
        }
        if (prtN->right) {
            nodeList[n++] = prtN->right;
        }
        i++;
    }
    
    for (int i = 0; i < n; i++)
        printf("%d ",nodeList[i]->data);
}


void levelOrder5(Node* root)
{
    Node * nodeList[10000];
    int n = 1;
    int i = 0;
    
    nodeList[0] = root;
    
    while (i < n) {
        
        if (nodeList[i]->left) {
            nodeList[n++] = nodeList[i]->left;
        }
        if (nodeList[i]->right) {
            nodeList[n++] = nodeList[i]->right;
        }
        i++;
    }
    
    for (int i = 0; i < n; i++)
        printf("%d ",nodeList[i]->data);
    
}


void levelOrder4(Node* root)
{
    Node * nodeList[10000];
    int n = 1;
    int i = 0;
    list<Node*> L;
    list<Node*>::iterator it = L.begin();
    L.insert(it,root);
    
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
    
    levelOrder5(head);
    
    
    return 0;
}


