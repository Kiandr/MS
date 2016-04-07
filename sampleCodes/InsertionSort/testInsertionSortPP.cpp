//
//  InsertionSortPP.cpp
//  InsertionSort
//
//  Created by Kian Davoudi-Rad on 2016-04-06.
//  Copyright © 2016 Kian Davoudi. All rights reserved.
//

#include "InsertionSortPP.hpp"
#include "stdlib.h"
// ================================================================================
// C++  method  service layer
// https://drive.google.com/file/d/0B1kNDgdfL1swRTJyUTU0V0dmTW8/view?usp=sharing
// ================================================================================

class Service:IService {
public:
    ISNode (*max) (ISNode *aNode);
    ISNode (*min) (ISNode *aNode);
    ISNode (*serach) (ISNode *aNode);
    ISNode (*procedure) (ISNode *aNode);
    ISNode (*successor) (ISNode *aNode);
    
    void (*insertANode) (ISNode *aNode);
    void (*insertAKey) (int aKey);
    void (* del) (ISNode *aNode);
};


// ================================================================================
// C++  method  Utility
// https://drive.google.com/file/d/0B1kNDgdfL1swRTJyUTU0V0dmTW8/view?usp=sharing
// ================================================================================
class Utility:IUtility{
    
public:
    Utility();
    ISNode *initWithInt(int _key)
    {
        ISNode *_tempNode;
        if (_key){
            _tempNode = (ISNode*) malloc (sizeof(ISNode));
            _tempNode->Key = &_key;
            _tempNode->l = NULL;
            _tempNode->r = NULL;
            _tempNode->p = NULL;
        }
        else{
            _tempNode = NULL;
            
        }
        
        return _tempNode;
        
    };

};