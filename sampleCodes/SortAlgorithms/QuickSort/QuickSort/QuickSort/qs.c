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

    // known condution to return back.
    if (length < 2)
        return;

    // new concept for me.
    int prtP = array[length / 2];
    int *prtL = array;
    // should reduce the 1 becuase array stars from 0.
    int *prtR = array + (length - 1);

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

    // this is a new concept to me as well
    int prtLeftLenghOfRemainingArray  = (int)(prtR - (array + 1)); // substract two pointers in a single array to find out their distance. its a hex calculation
    int prtRightLenghOfRemainingArray = (int)((array + length) - prtL);

    quick_sort(array, prtLeftLenghOfRemainingArray);
    quick_sort(prtL,  prtRightLenghOfRemainingArray);
}
