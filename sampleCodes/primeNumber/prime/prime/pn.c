//
//  pn.c
//  prime
//
//  Created by Kian Davoudi-Rad on 2017-08-24.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include "pn.h"


int isPrimeWithTwoVaribles	(int numberToBeTested, int divider){
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

    // known YES
    if ((numberToBeTested % divider) == 1)
        return 1;

    // known NO
    if ((numberToBeTested % divider) == 0)
        return 0;

    // eveything else
    else {


            return isPrimeWithTwoVaribles (numberToBeTested,  divider);
        }
    return 0;

};







float testOperation(int *x){

    float result = *x%2;

    return result;
}
