//
//  lc.c
//  letterCapitalize
//
//  Created by Kian Davoudi-Rad on 2017-09-11.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//
#include "stdio.h"
#include "lc.h"


/*

 Input:"hello world"
 Output:"Hello World"

 Input:"i ran there"
 Output:"I Ran There"
 */

void letterCapitalized (char str[]){



    char *prt = str;

    if (*prt >='a'&& *prt <= 'z')
    {
        printf(" %c",*prt-32);
        prt++;

    }

    while (*prt!='\0'){


        if (*prt!=' '){
            printf("%c",*prt);
            prt++;
        }
        if (*prt == ' ' ){
            prt++;
            printf(" %c",*prt-32);
            prt++;

        }
    }


}

void CapitalizeACharacter(char *str){

    char *prt = str;
    char *prtN = str;

    while (*prt!='\0'){


        printf("%c",*prt-32);

        char t = *prtN-32;
        printf("%c",t);
        
        prt++;
        prtN++;
        printf("\n");
        
        
    }
}
