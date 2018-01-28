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


bool remove(Node *head, int data){
    
    if (head==NULL)
        return false;
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
        return true;
    }
}
    
    int main(){
        Node *head  = NULL;
        head = append(head, 10);
        append(head, 11);
        append(head, 12);
        //print(head);
        remove(head, 11);
        print(head);
        
        
        return 0;
    }
