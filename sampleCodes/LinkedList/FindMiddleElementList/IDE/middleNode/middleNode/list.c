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

void printList(void){
    // TODO:
    // Print linkedList
    printf("Test was completed");

};
