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

struct{
    int *Key;
    struct Node *p;
    struct Node *l;
    struct Node *r;
    
}typedef ISNode;
// ================================================================================
// C method to define vital operations
// ================================================================================
struct{
    ISNode (*max) (ISNode *aNode);
    ISNode (*min) (ISNode *aNode);
    ISNode (*serach) (ISNode *aNode);
    ISNode (*procedure) (ISNode *aNode);
    ISNode (*successor) (ISNode *aNode);
    
    void (*insertANode) (ISNode *aNode);
    void (*insertAKey) (int aKey);
    void (* del) (ISNode *aNode);
    
    

}typedef ISService;

struct {
    ISNode *initANewNodeWithKey (int aKey){
        
        
        //return (ISNode*)malloc(sizeof(ISNode));;
        ISNode *_tempNode;
        if (aKey){
            _tempNode = (ISNode*) malloc (sizeof(ISNode));
            _tempNode->Key = &aKey;
            _tempNode->l = NULL;
            _tempNode->r = NULL;
            _tempNode->p = NULL;
        }
        else{
            _tempNode = NULL;
            
        }
        
        return _tempNode;
    };

}typedef Utility;




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

void *insertAKey (int aKey){
      //temp satisfier for complier;
    return &aKey;
    
};

void *del (ISNode *aNode){
    int *k;
    
    return k;
};





#endif /* InsertionSort_h */
