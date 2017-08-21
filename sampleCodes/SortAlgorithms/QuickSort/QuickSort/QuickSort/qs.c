//
//  qs.c
//  QuickSort
//
//  Created by Kian Davoudi-Rad on 2017-08-18.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include "qs.h"


int *Qs(const int *arrayHeader, int Length ){

    int *prtH = arrayHeader;
    int l = Length;
    int *prtP = arrayHeader;
    int *prtL =  prtH+1;
    int *prtR = prtH +(l-1);



    for (int i =0; i<l; i++)
    {
        while (*prtL<*prtP&& prtL<(prtH +(l-1))){
            prtL++;
        }
        while (*prtR>prtP && prtR>prtP){
            prtR--;
        }
        int temp = *prtL;
        *prtL=*prtR;
        *prtR = temp;
    }
    return arrayHeader;
}
