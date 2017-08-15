//
//  merge.h
//  mergeTwoLinkedLists
//
//  Created by Kian Davoudi-Rad on 2017-08-14.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#ifndef merge_h
#define merge_h

#include <stdio.h>


typedef struct {
    int val;
    struct node * next;

}node;

node *initHeaderWithEmptyModel (void);
int  AddNewNodeWithMode (node *header, int val);
int  ifHeaderIsEmpty (node * model);
void printList(node *header);
node *findMiddleNodeInLinkedList (node *header);
node *Merge(node *headerA, node* headerB);
node *MergeABinotC(node *headerA, node* headerB);


#endif /* merge_h */
