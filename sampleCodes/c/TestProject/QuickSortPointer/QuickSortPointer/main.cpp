#include "stdio.h"
void Swap(int *a, int *b)
{

	int temp = *a;
	*a = *b;
	*b = temp;
}



int *Partition(int *prtL, int *prtR, int *prtP) {
	while (!(prtL == prtR)) {
		if (*prtL < *prtP)
			prtL++;
		else if (*prtR >= *prtP)
			prtR--;

		else
			Swap(prtL, prtR);


		//unsigned char *byte = (unsigned char *)((unsigned char*)prtL - (unsigned char*)prtR);
	}
	return (0);
}



 int QS(int *prtL, int *prtR) {

	 int len = n / 2;

	if(prtL == prtR )
		return 0;
	else {

		Partition(prtL, prtR, prtPivot);
		int *prtToPrtL = prtL;
		while (n-- > 0)
			printf("-%d-",*prtToPrtL++);


		int midd = ((len - 1 / 2));
		int *NewPrtR = (prtL + midd - 2);
		int *NewPrtL = (prtL + midd + 2);
		int *newprtprtPivotL = (prtL + midd - 1);
		int *newprtprtPivotR = (prtL + midd + 1);

		QS(prtL, NewPrtR, newprtprtPivotL,len);
		//QS(NewPrtL , prtR , newprtprtPivotR, len);
	}
	return *prtL;
}

int main() {

	int array[] = { 35,33,42,10,14,19,27,44,26,31 };
	QS((array), (array + 8), (array + 9),10);
	return 0;
}