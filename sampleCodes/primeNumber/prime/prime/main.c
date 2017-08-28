//
//  main.c
//  prime
//
//  Created by Kian Davoudi-Rad on 2017-08-24.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {


    int array[] = { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 40,41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

    int *prtA = array;

    int length = sizeof(array)/sizeof(int);

    for (int i=0;i<length;i++){

        printf("%d\n", isPrimeWithTwoVaribles(*prtA++, (int)2));
    }
        return 0;
}
