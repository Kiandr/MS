//
//  lw.c
//  LongestWordInAString
//
//  Created by Kian Davoudi-Rad on 2017-08-29.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include "lw.h"

char *LongestWord(char str[]){


    int globalCounter = 0;
    int count = 0;
    char* prtB = str;


    char *lenOFArray = str;
    int l =0;

    while (*lenOFArray!='\0')
    {
        lenOFArray++;
        l++;
    }

    char prtNewWord [l];
    char *prtN = prtNewWord;
    int i =0;

    while (i<l){


        if ((*prtB>='a'&&*prtB<='z')||((*prtB>='A'&&*prtB<='Z')))
        {
            while (*prtB !='\0' && *prtB !=' ')
            {

                count++;

                *prtN++ = *prtB++;

                i++;
            }
            if (count>globalCounter)
            {
                globalCounter = count;
                *++prtN = '\0';
            }
            else count = 0;

        }
        count = 0;
        i++;
        prtB++;
        for (int j=0;j<l;j++)
            prtN [j] = ' ';
    }


    printf("%s",prtNewWord);



    return 0;





}




void CopyToNewArray (char *prt,char *prtPrev){

    char *prtS = prtPrev;
    char *prtE = prt;
    while (prtS<=prtE)
        printf("%c",*prtS++);
    printf("%\n",*prtS++);

};
void FindLongestWordWithinCharArray (const char *charArray){

    char *prt = charArray;
    char *prtPrev = prt;
    int gl =0;
    prtPrev = prt-gl;
    int l = 0;
    while (*prt!='\0'){
        while (*prt != NULL && (*prt != ' '))
        {

            prt++;
            l++;
        }

        if (l>gl){
            gl = l;
            prtPrev = prt-gl;
            CopyToNewArray (prt,prtPrev);
            prt++;
            prtPrev = prt;
            l=0;
        }
        else prt++;
    }
    
}




node* FindLongestWordWithinCharArrayOne (const char *charArray){

    char *prt = charArray;
    char *prtPrev = prt;
    int gl =0;
    prtPrev = prt-gl;
    int l = 0;

    node *newNode = (node*)(malloc(sizeof(node)));
    while (*prt!='\0'){
        while (*prt != NULL && (*prt != ' '))
        {

            prt++;
            l++;
        }

        if (l>gl){
            gl = l;
            prtPrev = prt-gl;
            CopyToNewArray (prt,prtPrev);
            newNode->l = gl;
            newNode->prt = prtPrev;
            
            prt++;
            prtPrev = prt;
            l=0;
        }
        else prt++;
    }


    return newNode;
    
}


