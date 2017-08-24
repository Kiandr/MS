//
//  main.c
//  QuickSort
//
//  Created by Kian Davoudi-Rad on 2017-08-18.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include <stdio.h>
#include "qs.h"

int main(int argc, const char * argv[]) {
    int array [] = {54,26,93,17,77,31,44,55,20};


	    int n = sizeof (array) / sizeof (int);
	    quick_sort(array, n);
	    printf("%d", array);

    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
