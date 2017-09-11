//
//  r.c
//  reverse
//
//  Created by Kian Davoudi-Rad on 2017-08-25.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//
#include "stdio.h"
#include "r.h"



void FirstReverse(char *arrayNew){

    char newA[5];
    char* prtN = newA;

    // go to the end of the aray
    char *prtEnd = arrayNew;
    while (*prtEnd!='\0')
    prtEnd++;

    prtEnd--;
    // start from back and come forward
    while (prtEnd>=arrayNew){


        *prtN++ = *prtEnd--;

    }

    for (int i=0;i<5;i++)
    printf("%c",newA[i]);
}



void FirstReverseN(char * str[]) {

    char *prtH = str;

    while (*prtH!='\0')
        prtH++;

    while (prtH-->=str)
        printf("%s", prtH);
    
}

int Factorial ( int a ){

    if (a ==0)
        return 0;
    if (a==1)
        return 1;
    
    return (a*Factorial(a-1));

}

void countLongestWorld (char header){


    int printArrau[10];

    for (int i=0;i<10;i++)
    {
        printf("%d index is %d", i,printArrau[i]);
    }



}



void LetterCapitalize(char * str[]) {

    // code goes here
    printf("%s", str);

}



