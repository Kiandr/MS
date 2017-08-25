//
//  main.c
//  prime
//
//  Created by Kian Davoudi-Rad on 2017-08-24.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int array[] = {23};
    int *prtA = array;
    int length = sizeof(array)/sizeof(int);
    for (int i=0;i<length;i++){
    printf("%d\n",(int)isPrimeWithTwoVaribles(*prtA++, 2));
    }
        return 0;
}
