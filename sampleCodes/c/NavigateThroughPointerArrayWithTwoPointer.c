#include "stdio.h"

void NavigateThroughPointerArrayWithTwoPointer(int *array, int n){

	int *prtL = array;
	int *prtR = array + n-1;

	while (prtL<=prtR)
	{
		printf("value of PrtL[%d]", *(int*)prtL);
		printf("address of PrtL[%p]\n",(void*)prtL);
		prtL++;
	}
}

//int main(){
//
//	int array [] = {35,33,42,10,14,19,27,44,26,31};
//	NavigateThroughPointerArrayWithTwoPointer(array, sizeof(array)/sizeof(int));
//	
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
--------------------------------------
*/