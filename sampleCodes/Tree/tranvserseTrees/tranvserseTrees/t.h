//
//  t.h
//  tranvserseTrees
//
//  Created by Kian Davoudi-Rad on 2017-09-05.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#ifndef t_h
#define t_h

#include "stdio.h"
#include "stdlib.h"

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
    struct node *root;
}node;

node *initTree(void);


#endif /* t_h */
