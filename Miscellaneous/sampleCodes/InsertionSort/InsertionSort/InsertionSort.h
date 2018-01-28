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
    int Key;
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
    
    void (*insert) (ISNode *aNode);
    void (* del) (ISNode *aNode);
    
    

}typedef ISService;
#endif /* InsertionSort_h */
