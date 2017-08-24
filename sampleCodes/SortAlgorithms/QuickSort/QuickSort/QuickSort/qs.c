//
//  qs.c
//  QuickSort
//
//  Created by Kian Davoudi-Rad on 2017-08-18.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#include "qs.h"


int *Qs(const int *arrayHeader, int Length ){

    /*
     Author: Kian D.Rad 
     Date: August 21st 2017
     README: QuickSort is a recursive solution.
     */

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


int *Qss(const int *arrayHeader, int Length ){

    /*
     Author: Kian D.Rad 
     Date: August 21st 2017
     README: QuickSort is a recursive solution.
     */

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


void quick_sort (int *array, int length) {
    if (length < 2)
        return;
    int prtP = array[length / 2];
    int *prtL = array;
    int *prtR = array + length - 1;
    while (prtL <= prtR) {
        if (*prtL < prtP) {
            prtL++;
        }
        else if (*prtR > prtP) {
            prtR--;
        }
        else {
            int t = *prtL;
            *prtL = *prtR;
            *prtR = t;
            prtL++;
            prtR--;
        }
    }
    quick_sort(array, prtR - array + 1);
    quick_sort(prtL, array + length - prtL);
}
