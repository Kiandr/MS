//
//  main.c
//  bubbleSort
//
//  Created by Kian Davoudi-Rad on 2017-08-17.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include <stdio.h>
#include "bs.h"

int main(int argc, const char * argv[]) {
    // insert code here...

    int array [] = {14,33,27,35,10};
    bubbleSort (array, (sizeof(array)/sizeof(int)));

    printf("Hello, World!\n");
    return 0;
}
