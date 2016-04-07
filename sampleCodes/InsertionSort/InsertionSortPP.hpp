//
//  InsertionSortPP.hpp
//  InsertionSort
//
//  Created by Kian Davoudi-Rad on 2016-04-06.
//  Copyright © 2016 Kian Davoudi. All rights reserved.
//

#ifndef InsertionSortPP_h
#define InsertionSortPP_h
#include "IInsertionSortPP.hpp"
#include "stdlib.h"

// ================================================================================
// C++  method  Utility
// https://drive.google.com/file/d/0B1kNDgdfL1swRTJyUTU0V0dmTW8/view?usp=sharing
// ================================================================================
class Utility:IUtilityBase{
    
public:
    
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

#endif /* InsertionSortPP_h */
