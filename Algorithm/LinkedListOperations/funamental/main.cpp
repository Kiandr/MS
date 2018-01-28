#include <iostream>


typedef struct Node{
    int data;
    struct Node *next;
}Node;


Node* append(Node *head, int data){
    
    if (head==NULL)
    {
        head = new Node();
        head->data= data;
        head->next = NULL;
        
    }
    else {
        Node *prtH = head;
        while (prtH->next != NULL){
            prtH =prtH->next;
        }
        prtH->next = new Node();
        prtH->next->data= data;
        prtH->next->next = NULL;
    }
    return head;
}


void print(Node *head)
{
    
    
    if (head==NULL)
        return ;
    Node *prtH = head;
    while (prtH != NULL){
        printf("prtH->next[%d],prtH->Data[%d],prtH[%p]\n",prtH->next,prtH->data,prtH);
        prtH =prtH->next;
    }
    
}



Node *Find(Node *head, int a){
    
    if (head==NULL)
        return head;
    else if (head->data == a)
        return head;
    else {
        Node *prtH = head;
        while (prtH->next != NULL){
            if (prtH->data == a)
                return prtH;
            prtH=prtH->next;
        }
        
    }
    return NULL;
}


Node* remove(Node *head, int data){
    
    if (head==NULL)
        return NULL;
    else if (head->next != NULL && head->data == data){
        Node *temp = head->next;
        head->data = 0;
        head->next = NULL;
        head =temp;
        return temp;
    }
    else if (head->next == NULL && head->data == data)
        return NULL;
    else {
        Node *prtH = head;
        Node *prev = head;
        while (prtH!= NULL && prev !=NULL){
            if (prtH->data == data)
            {
                prev->next = prtH->next;
                prtH =prtH->next->next;
            }
            else {
                prev = prtH;
                prtH = prtH->next;
            }
        }
        return head;
    }
}

int main(){
    Node *head  = NULL;
    head = append(head, 10);
    head = append(head, 11);
    head = append(head, 12);
    head = append(head, 13);
    //print(head);
    head = remove(head, 10);
    head = remove(head, 11);
    head = remove(head, 12);
    print(head);
    
    printf("Search for 12 returns [%p]\n",Find(head, 12));
    printf("Search for 13 returns [%p]\n",Find(head, 13));
    
    
    return 0;
}

