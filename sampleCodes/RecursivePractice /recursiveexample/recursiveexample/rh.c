//
//  rh.c
//  recursiveexample
//
//  Created by Kian Davoudi-Rad on 2017-08-22.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include "rh.h"

/*
 Author: Kian D.Rad
 Date:  August 27th 2017
 README: Recursive excersice, you should definitely master them all. 

 http://www.w3resource.com/c-programming-exercises/recursion/index.php

 This is also an other very very very good tutorial
 http://www.danzig.us/cpp/recursion.html
 
 */

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
