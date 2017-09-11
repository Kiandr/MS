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
            //   printf ("[ %c]\n",*prtN);
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

    for (int i = 0; i<length;i++)
        // code goes here
        printf("%c", newWork[i]);
    
};

/*
 
 
 Input:"hello*3"
 Output:"Ifmmp*3"

 Input:"fun times!"
 Output:"gvO Ujnft!"
 
 */





int rec (int total, int input){

    if (input == 0)
        return total;
//        else if ( input == 1)
//            return 1;
//        else
      //  {

            //total = total+(input);

            return rec(total+(input), input-1);
    //    }
  //  return total;
}




void SimpleAdding(int num[]) {
    int i = *num;
    int newNum = rec (0,i);
    // code goes here
    printf("%d", newNum);

}



void LetterCapitalize(char * str[]) {





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
    char  newWork[length*2];
    prtN = newWork;

    while (*prt!='\0'){
        if ((*prt>='a' && *prt<='z') || (*prt>='A' && *prt<='Z'))
        {
            int temp = *prt;
            /*a, e, i, o, u*/
            if (*prt>='a' && *prt<='z') {
                if (*prt== ' '){
                    *prtN= ' ';
                    prtN++;
                }
                *prtN = temp-32;
            }


            else *prtN = temp;




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

    for (int i = 0; i<length;i++)
        // code goes here
        printf("%c", newWork[i]);
    // code goes here
    //printf("%s", str-32);

}
