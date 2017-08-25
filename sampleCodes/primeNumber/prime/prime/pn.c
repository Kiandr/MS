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

//if a/a==1)
    return 0;
};


int isPrimeWithTwoVaribles	(int numberToBeTested, int startOfComparision){

    float comparision = (numberToBeTested/startOfComparision);

    while (numberToBeTested>=startOfComparision &&startOfComparision>=2){

        if (comparision==0)
            return 1;
        else {
            startOfComparision = startOfComparision+1;

            return isPrimeWithTwoVaribles (numberToBeTested,  startOfComparision);
        }
    }
    return 0;

};

float testOperation(int *x){

    float result = *x%2;

    return result;
}
