//
//  ss.h
//  ss
//
//  Created by Kian Davoudi-Rad on 2017-09-12.
//  Copyright © 2017 Kian. All rights reserved.
//

#ifndef ss_h
#define ss_h

#include <stdio.h>

void simpleSymbol (char *str[]);

#endif /* ss_h */

/*
 
 Using the C language, have the function SimpleSymbols(str) take the str parameter being passed and determine if it is an acceptable sequence by either returning the string true or false. The str parameter will be composed of + and = symbols with several letters between them (ie. ++d+===+c++==a) and for the string to be true each letter must be surrounded by a + symbol. So the string to the left would be false. The string will not be empty and will have at least one letter.

 
 
 Input:"+d+=3=+s+"
 Output:"true"

 Input:"f++d+"
 Output:"false"

 */
