//
//  main.c
//  LongestWordInAString
//
//  Created by Kian Davoudi-Rad on 2017-08-29.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include <stdio.h>
#include "lw.h"

int main(int argc, const char * argv[]) {
    //char array []="KIAN DAVOUDI RAD KD";
    //LongestWord(array);
  //  FindLongestWordWithinCharArray("KIAN DAVOUDI");

  //  FindLongestWordWithinCharArray("KIAN DAVOUDI");
    //FindLongestWordWithinCharArray("K D RAD");
   // FindLongestWordWithinCharArray(" K D R");

    node *n =(node*)(malloc(sizeof(node)));
    char *prtN = NULL;

     n = (node*) FindLongestWordWithinCharArrayOne ("KIAN DAVOUDI RAD");
     prtN = n->prt;



    for (int i=0;i<n->l; i++)
        printf("%c",*(prtN+i));

    return 0;
}
