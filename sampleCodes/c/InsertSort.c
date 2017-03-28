#include "stdio.h"


void InsertSort(int *array, int n) {
	
	int *prtL = array;
	int *prtR = array + (n - 1);
	
		while (prtL <= prtR) {
			printf("*prtL=%d--*prtR=%d\n", *prtL, *prtR);
			printf("*prtL=%p--*prtR=%p\n", prtL, prtR);
			if (*prtL > *prtR)
			{
				int i = *prtL;
				*prtL = *prtR;
				*prtR = i;
			}

			prtL++;
		}
}

//int main(){
//
//	int array [] = {35,33,42,10,14,19,27,44,26,31};
//	InsertSort(array, sizeof(array)/sizeof(int));
//	return 0;
//}
