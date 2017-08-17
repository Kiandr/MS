//
//  bs.c
//  bubbleSort
//
//  Created by Kian Davoudi-Rad on 2017-08-17.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include "bs.h"


void bubbleSort (int* headerToArray, int lenthOFArray){
    for (int i=0; i<lenthOFArray; i++){

    int *prt  = headerToArray;
    int *prtN = headerToArray+1;
    int *prtE = headerToArray + lenthOFArray-1  ;

    /* should make sure that prt and prtE both have been takes from the same malloc*/

       while (prt<prtE)
    {
        if (*prt>*prtN)
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
