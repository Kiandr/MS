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
    model->val  = 1;
    model->next = NULL;

    return model;
    
}


int  AddNewNodeWithMode (node *header, int val){
	/*
	Author: Kian D.Rad
	Date: August 4th 2017
	README: add new node at the tail. With new Val or with new Model
	TODO: 
	1- Transvers to the end of the linkedlist if header is not empty
	2- add new node at the end. 
	*/
	
	
    if (header->next)
		return 1;
	else return 0;
		
	
	
}

void printList(void){
    // TODO:
    // Print linkedList
    printf("Test was completed");

};
