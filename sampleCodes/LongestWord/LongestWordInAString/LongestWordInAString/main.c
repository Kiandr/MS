//
//  main.c
//  LongestWordInAString
//
//  Created by Kian Davoudi-Rad on 2017-08-29.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    //char array []="KIAN DAVOUDI RAD KD";
    //LongestWord(array);
    FindLongestWordWithinCharArray("KIAN DAVOUDI");

    FindLongestWordWithinCharArray("KIAN DAVOUDI RAD");
    FindLongestWordWithinCharArray("K D RAD");
    FindLongestWordWithinCharArray(" K D R");

    return 0;
}
