//
//  main.c
//  tranvserseTrees
//
//  Created by Kian Davoudi-Rad on 2017-09-05.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include "stdio.h"
# include "t.h"




int main(int argc, const char * argv[]) {

    node *root  = (node*)(malloc(sizeof( node)));
    root->left  = NULL;
    root->right = NULL;
    root->root  = NULL;
    root->val = 100;



    struct node * n = (node*)malloc(sizeof(node));
    n->left = NULL;
    n->right = NULL;
    n->val = 10;
    n->root = NULL;
    addNode(root, n);

    struct node * n2 = (node*)malloc(sizeof(node));
    n2->left = NULL;
    n2->right = NULL;
    n2->val = 20;
    n2->root = NULL;
    addNode(root, n2);


    struct node * n3 = (node*)malloc(sizeof(node));
    n3->left = NULL;
    n3->right = NULL;
    n3->val = 5;
    n3->root = NULL;
    addNode(root, n3);

    struct node * n4 = (node*)malloc(sizeof(node));
    n4->left = NULL;
    n4->right = NULL;
    n4->val = 25;
    n4->root = NULL;
    addNode(root, n4);

    return 0;
}
