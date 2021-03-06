//
//  list.c
//  middleNode
//
//  Created by Kian Davoudi-Rad on 2017-08-04.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//
#include "stdio.h"
#include "stdlib.h"
#include "list.h"


node *initHeaderWithEmptyModel (void){

	node *model = (node*) malloc(sizeof(node));
    model->val  = 0;
    model->next = NULL;

    return model;
    
}


int  ifHeaderIsEmpty (node * model){
	/*
	Author: Kian D.Rad
	Date: August 4th 2017
	README: add new node at the tail. With new Val or with new Model
	TODO: 
	1- Transvers to the end of the linkedlist if header is not empty
	2- add new node at the end. 
	*/
	
	
    if (model->next)
		return 1;
	else return 0;
		
	
	
}

int  AddNewNodeWithMode (node *header, int val){

    node *prt = header;
    while (prt->next){
        prt= (node*)prt->next;
    }
    prt->next = (node *)(malloc(sizeof(node) ));
	prt=(node*)prt->next;
	prt->next = NULL;
	prt->val = val;

    return 1;

}

void printList(node *header){


    node *prt = header;
	while  (prt){
        printf("node =[%p] | node->val [%d] |  node-next = [%p]\n", prt , prt->val, prt->next);
        prt= (node*)prt->next;
    }
    printf("Test was completed\n");

};


node *findMiddleNodeInLinkedList (node *header){
	
	/*
	
	Author: Kian D.Rad
	Date:  August 6th 2017
	README: https://coderbyte.com/algorithm/linked-list-middle-element
	TODO: Use fast and slow runner, walk fast runner to the end of the list
		
	*/
	
	node *prtF = header;
	node* prtS = header;
	while (prtF->next){
		// Do it towise
//		prtF = prt->next;
//		prtF = prt->next;
		
		// or do this. 
		prtF= (node*)((node*)(prtF->next))->next;
		prtS= (node*)prtS->next;
		
	}
	
	return prtS;
	
	
	
	
	
};
