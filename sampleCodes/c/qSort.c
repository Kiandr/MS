#include "stdio.h"
void qSort(int *array, int n){
	
	int pivote = array + n - 1 / 2;
	int *prtL = array;
	int *prtR = array + n-1;
	while (prtL<=prtR)
	{
		if (*prtL < pivote)
			prtL++;
		else if
			(*prtR > pivote)
			prtR++;
		else { 
			int t = *prtL;
			*prtL = *prtR;
			*prtL = t;
			prtL++;
			prtR++;
		}
	}
}
//int main(){
//
//	int array [] = {35,33,42,10,14,19,27,44,26,31};
//	qSort(array, sizeof(array)/sizeof(int));
//	return 0;
//}
/*
--------------------------------------
How to print value of pointer pointer?
--------------------------------------
void quickSort(int *array, int n){

// PonterToPointer
int *prtL = array;
int *prtR = array + n-1;
while (prtL<prtR)
	{
	printf("value of PrtL[%d]", *(int*)prtL);
	printf("address of PrtL[%p]\n",(void*)prtL);
	prtL++;
	}
}
*/