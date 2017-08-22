//
//  rh.c
//  recursiveexample
//
//  Created by Kian Davoudi-Rad on 2017-08-22.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include "rh.h"

void printUpToFifty 	(int a){

    // known condition A

    if (a == 50)
        return;

    // unknonw condition
    return printUpToFifty(a++);

};

void printDown  (int a){
    // known condition

    if (a==0)
        return;

    // unknonw condition
    return printDown (a--);
};

int fabenacci	(int a){
    //known condition
    if (a ==0)
        return 0;
    if (a==1)
        return 1;

    return fabenacci( (a-2)+(a-1) );

};

int isPrime	(int a, int b){
    
    if (a==b)
        return 1;
    if (a%b == 0) return 0;
    
    return isPrime( a , (b+1));
    
};
