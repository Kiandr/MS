//
//  ci.c
//  convertIntToHour
//
//  Created by Kian Davoudi-Rad on 2017-09-20.
//  Copyright © 2017 Kian. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "ci.h"


void TimeConvert(int num[]) {

    int hour = 0;
    int min = 0;
    int n= num;

    hour = n/60;
    min = n%60;

    printf("%d:%d", n/60, n%60);

};
