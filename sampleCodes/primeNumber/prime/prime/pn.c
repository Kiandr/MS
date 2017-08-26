//
//  pn.c
//  prime
//
//  Created by Kian Davoudi-Rad on 2017-08-24.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include "pn.h"
int isPrime(int a){

/*
 Author: Kian D.Rad 
 Date: August 26th2017
 README: prime number is x which x%x == 1 and x%1 = x
         That is a number that could be divided only with itself and 1
 */


    return 0;
};


int isPrimeWithTwoVaribles	(int numberToBeTested, int startOfComparision){

    float comparision = (numberToBeTested%startOfComparision);

    //while (numberToBeTested>=startOfComparision &&startOfComparision>=2){


    /*
     Auhor: Kian D.Rad
     Date: August 25th2017
     README: 
     Simpel Math: 
     There are three known cases; 
     1- when x%y reminder == 1 then YES it is A     PRIME
     2- when x%y reminder == 0 then NO  it is NOT   PRIME
     3- Any other case: wheren the divider is going to be 7,6,5,4,3,2,1 0 when 0 function returns.

     */
    if (comparision==1)
        return 1;

    if (numberToBeTested%startOfComparision ==0)
        return 0;

        else {
            //startOfComparision = startOfComparision+1;

            return isPrimeWithTwoVaribles (numberToBeTested,  startOfComparision-1);
        }
   // }
    return 0;

};

float testOperation(int *x){

    float result = *x%2;

    return result;
}
