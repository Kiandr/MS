//
//  main.cpp
//  InsertionSort
//
//  Created by Kian Davoudi-Rad on 2016-04-06.
//  Copyright © 2016 Kian Davoudi. All rights reserved.
//
#include <iostream>
#include "InsertionSort.h"
//#include "stdlib.h"
//#include "InsertionSort.h"
//#include "IInsertionSortPP.hpp"


int main(int argc, const char * argv[]) {
    
    // Please reffer to https://drive.google.com/folderview?id=0B1kNDgdfL1swclNicUgySnhLMXM&usp=sharing for theory.
    // Step 1: What the data structure.
    
    
    // This is a c format
    IUtility    *util =(IUtility*)malloc(sizeof(IUtility));
    
    
    ISService *service = (ISService*)malloc(sizeof(ISService));
    ISNode* head = util->initANewNodeWithKey(10.00);
    
    service->insertANode(head);
    service->insertANode(util->initANewNodeWithKey(12.00));
    service->insertANode(util->initANewNodeWithKey(9.00));
    service->insertANode(util->initANewNodeWithKey(13.00));
    service->insertANode(util->initANewNodeWithKey(7.00));
    service->insertANode(util->initANewNodeWithKey(15.00));
    service->insertANode(util->initANewNodeWithKey(5.00));
    service->insertANode(util->initANewNodeWithKey(17.00));
    service->insertANode(util->initANewNodeWithKey(3.00));
    service->insertANode(util->initANewNodeWithKey(19.00));
    service->insertANode(util->initANewNodeWithKey(1.00));
    
    
        
        ISNode* prt = (ISNode*) service->head;
        while (prt->r !=NULL)
        {
            
            std::cout<<prt->key;
            prt = (ISNode*) prt->r;
        }
    
    

    
    /*
    int InputR[] = {12,14,16};
    int InputL[] = {11,13,15};
    int *prtToInputR = InputR;
    int *prtToInputL = InputL;
    
    while ((*prtToInputR)&&(*prtToInputR>0)){
        
        service->insertANode(util->initANewNodeWithKey(*prtToInputR));
        prtToInputR++;
        
    
    };
    
    while ((*prtToInputL)&&(*prtToInputL>0)){
        
        service->insertANode(util->initANewNodeWithKey(*prtToInputL));
        prtToInputL++;
    };
    
    
    */
    
    
    free(util);
    
    
    
    //    ISNode *head =
    //util->initWithInt(input);
    //    int test  = (int)*head->Key;
    //    std::cout<<test;
    //     //util->initWithInt(12);
    //Utility *util = (Utility*) malloc (sizeof(Utility));
    
    //int testNumber = 10;
    //  util->initANewNodeWithKey(testNumber);
    //    service->serach(head);
    
    // initate a new node
    //ISNode *aNewNode = (ISNode*)malloc(sizeof(ISNode));
    
    
    // insert a new
    //service->insertANode(head, util->initANewNodeWithKey(12));
    //service->insertAKey( head, 12);
    
    
    
    
    
    
    
    return 0;
}
