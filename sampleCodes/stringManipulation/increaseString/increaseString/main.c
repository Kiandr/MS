//
//  main.c
//  increaseString
//
//  Created by Kian Davoudi-Rad on 2017-09-08.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include <stdio.h>
#include "is.h"


int main(int argc, const char * argv[]) {
    // disable stdout buffering
    setvbuf(stdout, NULL, _IONBF, 0);
    char str [] = "hello*3";
    // keep this function call here
    LetterChanges("Argument goes here");

    return 0;
}
/*


 Input:"hello*3"
 Output:"Ifmmp*3"

 Input:"fun times!"
 Output:"gvO Ujnft!"

 */
