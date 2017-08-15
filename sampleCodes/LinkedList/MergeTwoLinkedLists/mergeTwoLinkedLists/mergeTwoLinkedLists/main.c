//
//  main.c
//  mergeTwoLinkedLists
//
//  Created by Kian Davoudi-Rad on 2017-08-14.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include <stdio.h>
#include "merge.h"
int main(int argc, const char * argv[]) {
    // insert code here...


    node * HeaderA = initHeaderWithEmptyModel();
    node * HeaderB = initHeaderWithEmptyModel();

    
    // build two lists:
    AddNewNodeWithMode (HeaderA, 50);
    AddNewNodeWithMode (HeaderB, 51);
    AddNewNodeWithMode (HeaderA, 52);
    AddNewNodeWithMode (HeaderB, 53);
    AddNewNodeWithMode (HeaderA, 54);
    AddNewNodeWithMode (HeaderB, 55);


    // Print A and B
    printList(HeaderA);
    printList(HeaderB);



    //printf("Test Merge!\n");
   // node *meregedNode = Merge(HeaderA, HeaderB);


    printf("Test Merge AB into C!\n");

    printList( MergeABinotC((node*)HeaderA, (node*)HeaderB));



    printf("Hello, END OF FUNCTION!\n");
    return 0;
}
