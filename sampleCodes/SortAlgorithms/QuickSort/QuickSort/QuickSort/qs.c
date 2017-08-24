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


void quick_sort (int *a, int n) {
    if (n < 2)
        return;
    int p = a[n / 2];
    int *l = a;
    int *r = a + n - 1;
    while (l <= r) {
        if (*l < p) {
            l++;
        }
        else if (*r > p) {
            r--;
        }
        else {
            int t = *l;
            *l = *r;
            *r = t;
            l++;
            r--;
        }
    }
    quick_sort(a, r - a + 1);
    quick_sort(l, a + n - l);
}
