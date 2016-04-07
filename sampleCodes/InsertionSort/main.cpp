//
//  main.cpp
//  InsertionSort
//
//  Created by Kian Davoudi-Rad on 2016-04-06.
//  Copyright © 2016 Kian Davoudi. All rights reserved.
//

#include "stdlib.h"
#include "InsertionSort.h"
int main(int argc, const char * argv[]) {
    
    // Please reffer to https://drive.google.com/folderview?id=0B1kNDgdfL1swclNicUgySnhLMXM&usp=sharing for theory.
    // Step 1: What the data structure.
    
    ISNode *head;
    
    ISService *service = (ISService*)malloc(sizeof(ISService));
    Utility *util = (Utility*) malloc (sizeof(Utility));
    
    int testNumber = 10;
     util->initANewNodeWithKey(testNumber);
    
    // initate a new node
    //ISNode *aNewNode = (ISNode*)malloc(sizeof(ISNode));
    
    
    // insert a new
    //service->insertANode(head, util->initANewNodeWithKey(12));
    //service->insertAKey( head, 12);
    
    
    
    
    
    
    
    return 0;
}
