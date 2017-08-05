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
    if (prt->next){
        prt=prt->next;
    }
    prt->next = (node *)malloc(sizeof(node));
	prt=prt->next;
	prt->next = NULL;
	prt->val = val;

    return 1;

}

void printList(node *header){


    node *prt = header;
    if (prt->next){
        printf("node =[%p] | node->val [%d] |  node-next = [%d]", prt , prt->val, prt->next);
        prt=prt->next;
    }
    printf("Test was completed");

};
