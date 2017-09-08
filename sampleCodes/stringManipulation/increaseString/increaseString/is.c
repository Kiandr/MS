//
//  is.c
//  increaseString
//
//  Created by Kian Davoudi-Rad on 2017-09-08.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include "is.h"
void LetterChanges(char * str[]) {


    char*  prt = str;

    // getTheLentghOfString

    char *prtL = str;
    int length = 0;

    while (*prtL!='\0')
    {
        length++;
        prtL++;
    }



    char *prtN = NULL;
    char  newWork[length];
    prtN = newWork;

    while (*prt!='\0'){
        if ((*prt>='a' && *prt<='z') || (*prt>='A' && *prt<='Z'))
        {
                int temp = *prt;
                /*a, e, i, o, u*/
            if (*prt=='a'|| *prt=='e' || *prt=='i' || *prt=='o' || *prt=='u' ){
                *prtN = temp-32;
            }


            else *prtN = temp+1;
            printf ("[ %c]\n",*prtN);
            prtN++;
            prt++;
        }
        else
        {
            *prtN=*prt;
            prtN++;
            prt++;
        }


    }


    // code goes here
    printf("%s", newWork);
    
};

/*
 
 
 Input:"hello*3"
 Output:"Ifmmp*3"

 Input:"fun times!"
 Output:"gvO Ujnft!"
 
 */
