//
//  InsertionSort.h
//  InsertionSort
//
//  Created by Kian Davoudi-Rad on 2016-04-06.
//  Copyright © 2016 Kian Davoudi. All rights reserved.
//

    

#ifndef InsertionSort_h
#define InsertionSort_h
// ================================================================================
// C method  structure of the node accordin to MIT book
// https://drive.google.com/file/d/0B1kNDgdfL1swRTJyUTU0V0dmTW8/view?usp=sharing
// ================================================================================

typedef struct{
    double *key;
    struct Node *p;
    struct Node *l;
    struct Node *r;
    struct Node *next;
    
    
} ISNode;
// ================================================================================
// C method to define vital operations
// ================================================================================
struct{
    
    ISNode *head;
    
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
        // set pointers
        ISNode *prtToH = head;
        
        
        // set pointer
        if (head==NULL)
        {
            head = aNode;
            return this;
        }
        // transverse
        while(prtToH->l || prtToH->r)
        {
            // right navigate
            if (*prtToH->key < *aNode->key)
            {
                prtToH = (ISNode*)prtToH->r;
            }
            // right navigate
        else{
            prtToH = (ISNode*)prtToH->l;
             }
        }
        
        if (*prtToH->key < *aNode->key)
        {
            aNode->p = (Node*) prtToH;
            prtToH->r =(Node*) aNode;
        }
        else {
            aNode->p  = (Node*) prtToH;
            prtToH->l = (Node*) aNode;
        }        
        return this;
    };
    
    void *del (ISNode *aNode){
        int *k;
        
        return k;
    };
    
    

}typedef ISService;

struct {
    ISNode *initANewNodeWithKey (double aKey){
        ISNode *_tempNode;
        if (aKey){
            _tempNode = (ISNode*) malloc (sizeof(ISNode));
            _tempNode->key  = &aKey;
            _tempNode->l    = NULL;
            _tempNode->r    = NULL;
            _tempNode->p    = NULL;
            _tempNode->next = NULL;
            
        }
        else{
            _tempNode = NULL;
            
        }
        
        return _tempNode;
    };

}typedef IUtility;




// ================================================================================
// C implementation Service Layer should take place inside the struct,otherwise the struct does not know where to find address of the implementation.
// ================================================================================




#endif /* InsertionSort_h */
