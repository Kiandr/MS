//
//  main.c
//  middleNode
//
//  Created by Kian Davoudi-Rad on 2017-08-04.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include <stdio.h>
#include "list.h"

int main(int argc, const char * argv[]) {



     node *header = NULL;
     header = initHeaderWithEmptyModel();

    /*
     Author: Kian D.Rad
     Date August 4th 2017
     README: Test2.
     TODO: see if the header is empty.
     */

    node *emptyHeader = (node*)malloc (sizeof(node));


    // FALIED
    int FAILED =   AddNewNodeWithMode (emptyHeader, NULL);

    //PASSED
    emptyHeader->next = (node*)malloc (sizeof(node));
    int PASSED =   AddNewNodeWithMode (emptyHeader, NULL);


    return 0;
}
