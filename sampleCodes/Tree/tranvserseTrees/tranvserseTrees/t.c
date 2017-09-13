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

node *buildNewNode (node * root, node *incomingNode){

    node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = incomingNode->val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->root = root;

    return newNode;
}

node* addNode(node * root, node * node){

    struct node * prtRoot  = root;
    struct node * prtN = node;

    if (root == NULL )
        return root;

    if (root->left != NULL && & root->right!=NULL){

        if ( prtN->val > prtRoot->val)
            return addNode(prtRoot->right, node);

        else if  ( prtN->val < prtRoot->val)
           return  addNode(prtRoot->left, node);

    }
    else {


        if (prtRoot->val >prtN->val)
            prtRoot->left = buildNewNode(prtRoot, prtN);



        else if (prtRoot->val <prtN->val)
            prtRoot->right = buildNewNode(prtRoot,prtN);
    }

   // return prtRoot;
    
    return 0;
    
}
