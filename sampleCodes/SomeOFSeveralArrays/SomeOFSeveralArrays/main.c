//
//  main.c
//  SomeOFSeveralArrays
//
//  Created by Kian Davoudi-Rad on 2017-09-11.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include <stdio.h>
#include "sa.h"
int main(int argc, const char * argv[]) {


    int prtHeader[3][4]={
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };


    printArray(prtHeader);
  
    return 0;
}
