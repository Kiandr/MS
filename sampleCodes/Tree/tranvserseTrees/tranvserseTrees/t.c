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

node *buildNewNode (node * root, node *newNode){


    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = newNode->val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->root = root;
    return newNode;
}


node* addNode(node * root, node * node){

    struct node * prtR  = root;
    struct node * prtN = node;

    if (root == NULL )
        return root;
    if (root->left != NULL && & root->right!=NULL){

        if ( prtN->val > prtR->val)
            addNode(prtR->left, node);

        else
            addNode(prtR->right, node);

    }
    else {


        if (prtR->val >prtN->val)
            prtR->left = buildNewNode(prtR, prtN);



        if (prtR->val <prtN->val)
            prtR->right = buildNewNode(prtR,prtN);
    }

    return prtR;
    
    
    
};
