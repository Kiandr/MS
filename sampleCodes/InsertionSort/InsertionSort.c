//
//  InsertionSort.c
//  InsertionSort
//
//  Created by Kian Davoudi-Rad on 2016-04-06.
//  Copyright © 2016 Kian Davoudi. All rights reserved.
//

#include "InsertionSort.h"
#include "stdio.h"


// ================================================================================
// C implementation Service Layer
// ================================================================================

ISNode *max (ISNode *aNode){
    ISNode *prtH = aNode;
    return prtH;
};

ISNode *min (ISNode *aNode){
    ISNode *prtH = aNode;
    return prtH;
};

ISNode *search (ISNode *aNode){
    ISNode *prtH = aNode;
    return prtH;
};

ISNode *procedure (ISNode *aNode){
    ISNode *prtH = aNode;
    return prtH;
};

ISNode *successor (ISNode *aNode){
    ISNode *prtH = aNode;
    return prtH;
};


void *insertANode (ISNode *aNode){
    int *k;
    
    return k;
};

void *insertAKey (int *aKey){
    // Initate a new node.
    if (!aKey){
        ISNode *tempNode = (ISNode*) malloc (sizeof(ISNode));
        tempNode->Key = aKey;
        tempNode->l = NULL;
        tempNode->r = NULL;
        tempNode->p = NULL;
        
    }
    else{
        return NULL;
        
    }
    // find the location
    
    // Insert to the location

    
    
    //temp satisfier for complier;
    return &aKey;
    
};


void *del (ISNode *aNode){
    int *k;
    
    return k;
};

// ================================================================================
// C implementation Utility Layer
// ================================================================================


ISNode *initANewNodeWithKey (int aKey){
    if (!aKey){
    ISNode *tempNode = (ISNode*) malloc (sizeof(ISNode));
        tempNode->Key = aKey;
        tempNode->l = NULL;
        tempNode->r = NULL;
        tempNode->p = NULL;
        return tempNode;
    }
    else{
        return NULL;
    
    }
    

};


