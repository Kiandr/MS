//
//  lw.h
//  LongestWordInAString
//
//  Created by Kian Davoudi-Rad on 2017-08-29.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#ifndef lw_h
#define lw_h

#include <stdio.h>
typedef struct {
    int l;
    char *prt;
}node;

char *LongestWord(char str[]);
void FindLongestWordWithinCharArray (const char *charArray);
node* FindLongestWordWithinCharArrayOne (const char *charArray);
#endif /* lw_h */
