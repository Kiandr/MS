#include <iostream>
#include <vector>

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


Node * AddCycle(Node *head, int a){
    if (head == NULL)
        return NULL;
    else if (head->next!=NULL && head->next->data == a)
        return NULL;
    
    else {
        Node * prtH = head;
        while (prtH->next !=NULL)
            prtH=prtH->next;
        prtH->next = head->next->next;
        
        
        
    }
    
    
    
    return head;
}


bool  IsCycle(Node *head)
{
    if (head == NULL){ return false;}
    else if (head->next == NULL){ return false;}
	else if (head->next == head){return true;}
    else  {
        // Floyd Algorithm
        Node *slow = head;
        Node *fast = head->next;
        while (fast->next != NULL && slow->next != NULL){
            if (slow == fast){ return true;}
            else {
                slow = slow->next;
                fast = fast = fast->next->next;
            }
        }
    }
    return false;
    
}

// reverse 
Node * reverse (Node * head){
	
	if (head == NULL)
		return NULL;
	else {
		vector<Node> V;
		Node *prtH = head;
		Node* headN = new Node();
		while (prtH->next != NULL)
			V.push_bash(prtH);
		for (int i = V.capacity();,i>=0;i--)
			headN = append(head,V[i]);
		
		
	}
}


int main(){
    Node *head  = NULL;
    head = append(head, 10);
    head = append(head, 11);
    head = append(head, 12);
    head = append(head, 13);
    head = append(head, 14);
    head = append(head, 15);
    print(head);
   // head = AddCycle(head,12);
    reverse(head);
//    printf(" is cycle or nor = [%d]", IsCycle(head));
    return 0;
}

