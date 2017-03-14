#include "stdio.h"
void Swap(int *a, int *b)
{

	int temp = *a;
	*a = *b;
	*b = temp;
}



int *Partition(int *prtL, int *prtR, int *prtPivot) {
	while (!(prtL == prtR)) {
		if (*prtL < *prtPivot)
			prtL++;
		else if (*prtR >= *prtPivot)
			prtR--;

		else
			Swap(prtL, prtR);
	}
	return (prtL);
}



 int QS(int *prtL, int *prtR) {

	

	if(*prtL - *prtR>0 )
		return 0;
	else {

		int *prtPartition = Partition(prtL, prtR, prtR);
		//// print array
		//int *prtToPrtL = prtL;
		//while (n-- > 0)
		//	printf("-%d-",*prtToPrtL++);


		//int midd = ((len - 1 / 2));
		//int *NewPrtR = (prtL + midd - 2);
		//int *NewPrtL = (prtL + midd + 2);
		//int *newprtprtPivotL = (prtL + midd - 1);
		//int *newprtprtPivotR = (prtL + midd + 1);

		QS(prtL, prtPartition - 1);
		QS(prtPartition+1 , prtR );
	}
	return *prtL;
}

//int main() {
//
//	int array[10] = { 35,33,42,10,14,19,27,44,26,31 };
//	QS(array, array+9);
//	return 0;
//}