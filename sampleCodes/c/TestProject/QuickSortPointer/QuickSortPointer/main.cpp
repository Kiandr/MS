#include "stdio.h"





//QuckSort(void *Array, int lenOfArray) {
//
//
//
//};

// How to find length of static int array given the fact that the array is static within allloc of the function. 
size_t LenthOfStaticArary(int a[]) {
	
	static int array[10] = { 35,33,42,10,14,19,27,44,26,31 };
	int size = sizeof(array);
	int sizeOfInt = sizeof(int);
	size_t r = size / sizeOfInt;

	return r;
};

int main() {

	static int array[10] = { 35,33,42,10,14,19,27,44,26,31 };
	// based on the compiler the size of int changes from 2 bytes to 4 bytes, however, an int array is member*sizeofInt=sizeofArray => members = sizeOfArray/sizeofInt simpel math!
	int sizeOfArr = sizeof(array)/sizeof(int);
	int  length = LenthOfStaticArary(array);
	if (sizeOfArr != length)
		return 0;

	return 0;
}