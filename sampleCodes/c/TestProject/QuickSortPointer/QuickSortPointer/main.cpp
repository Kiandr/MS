<<<<<<< .mine
#include "stdio.h"























































=======
#include "stdio.h"


void QuckSort(int *array, int length) {
	//if (length <= 0)
	//	return;
	while (*array > *(array + (length - 1))&& length <= 0)
	{
	
	int n = length / 2;
	int *prtR = array + (length - 1);
	int *prtL = array;
	int p = *(array + n);


	//while (*prtL <= *prtR) {

	if (*prtL < p)
		prtL++;
	else if (*prtR > p)
		prtR--;
	else
	{
		int t = *prtL;
		*prtL = *prtR;
		*prtR = t;
	}
	//}
	QuckSort(array, length / 2);
	QuckSort(array + (n + 1), length / 2);
}
	return;
};

// How to find length of static int array given the fact that the array is static within allloc of the function. 
size_t LenthOfStaticArary(int a[]) {
	
	static int array[5] = { 35,33,42,10,14 };
	int size = sizeof(array);
	int sizeOfInt = sizeof(int);
	size_t r = size / sizeOfInt;

	return r;
};
//
//int main() {
//
//	static int array[5] = { 35,33,42,10,14 };
//	// based on the compiler the size of int changes from 2 bytes to 4 bytes, however, an int array is member*sizeofInt=sizeofArray => members = sizeOfArray/sizeofInt simpel math!
//	int sizeOfArr = sizeof(array)/sizeof(int);
//	int  length = LenthOfStaticArary(array);
//	if (sizeOfArr != length)
//		return 0;
//	QuckSort(array, length);
//	return 0;
//}
>>>>>>> .theirs
