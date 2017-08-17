//
//  bs.c
//  bubbleSort
//
//  Created by Kian Davoudi-Rad on 2017-08-17.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include "bs.h"


void bubbleSort (int* headerToArray, int lenthOFArray){
    int *prt  = headerToArray;
    int *prtN = headerToArray++;
    int *prtE = headerToArray + lenthOFArraygit  ;

    /* should make sure that prt and prtE both have been takes from the same malloc*/

    for (int i=0; i<lenthOFArray; i++){
    while (prt>prtE)
    {
        if (*prt<*prtN)
        {
            int t = *prt;
            *prt = *prtN;
            *prtN = t;
        }
        
        prt++;
        prtN++;
        
    }
    }

};
