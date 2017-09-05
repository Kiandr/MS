//
//  t.c
//  tranvserseTrees
//
//  Created by Kian Davoudi-Rad on 2017-09-05.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include "t.h"
#include "stdio.h"
#include "stdlib.h"



node *initTree(void){

    node *root  = (malloc(sizeof( node)));
    root->left  = NULL;
    root->right = NULL;
    root->root  = NULL;

    return root;
};

void addNode(node * root, node * node){

    struct node * prtR  = root;
    struct node * prtN = node;

    if (root->left != NULL && root->right){

        if ((int*)prtN->val > (int*)prtR->val)
            addNode(prtR->left, node);

        else
            addNode(prtR->right, node);

    }

    if ((int*)prtN->val > (int*)prtR->val)
    {
        prtR->left = (struct node*)malloc(sizeof(struct node));
        *((struct node*)(prtR->left)->val) = (int*)prtN->val;
        prtR->left->left = NULL;
        prtR->left->right = NULL;
        prtR->left->root = prtR;

    }

    else
        addNode(prtR->right, node);




};
