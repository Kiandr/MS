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

void bubbleSort (char* headerToArray, int lenthOFArray){
    for (int i=0; i<lenthOFArray; i++){

        char *prt  = headerToArray;
        char *prtN = headerToArray+1;
        char *prtE = headerToArray + lenthOFArray-1  ;

        /* should make sure that prt and prtE both have been takes from the same malloc*/

        while (prt<prtE)
        {
            if (*prt>*prtN)
            {
                char t = *prt;
                *prt = *prtN;
                *prtN = t;
            }

            prt++;
            prtN++;

        }
    }

    printf("%s",headerToArray);
};
