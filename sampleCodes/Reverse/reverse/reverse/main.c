//
//  main.c
//  reverse
//
//  Created by Kian Davoudi-Rad on 2017-08-25.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "r.h"

int main(int argc, const char * argv[]) {


    char array []={"ABCD"};

    FirstReverse(array);
    FirstReverseN(array);
    for (int i = 0; i<10;i++)
    printf("\nFactorial of %d is %d\n",i,Factorial (  i));

    return 0;
}
