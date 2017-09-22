//
//  SC.c
//  SortingChar
//
//  Created by Kian Davoudi-Rad on 2017-09-20.
//  Copyright © 2017 Kian. All rights reserved.
//

#include "SC.h"
void AlphabetSoup(char * str[]) {

    char *prtLen = str;
    int l = 0;
    char prtSmallerChar[1];
    *prtSmallerChar = *str;

    while (*prtLen !='\0')
    {
         if (*prtSmallerChar>*prtLen)
            *prtSmallerChar=*prtLen;

        l++;
        prtLen++;
    }


    

    // code goes here
    printf("%c", *prtSmallerChar);

}
