/*
 Author: Kian D.Rad
 Date: 	August 4th 2017
 ReadMe: Find a node within the linkedlist. use fast and slow runner terchnique

 TODO:
	1- Build a header, intiazlie the structure header with NIL
	2- Add 7 nodes to linked list
	3- Implemnted the function that returns the middle clas
 */



#ifndef list_h
#define list_h
typedef struct {
    int val;
    struct node * next;

}node;


node *initHeaderWithEmptyModel (void);
int  AddNewNodeWithMode (node *header, int val);
int  ifHeaderIsEmpty (node * model);
void printList(node *header);

#endif /* list_h */
