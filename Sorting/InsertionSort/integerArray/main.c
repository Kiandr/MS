#include "stdio.h"

void printArray(int const *header, int len) {


	for (int i = 0; i<len; i++) {
		printf(" array[%d] = [%d] \n", i, header[i]);

	}

}

void swap(int *a, int*b) {


	int temp = *a;
	*a = *b;
	*b = temp;

}

void sortArray(int const *header, int len) {


	int *prtH = (int*)header;

	// this is a temp value that changes based on the iteration, its the right memebr of the first member of unsorted array
	int key = 0;

	for (int i = 0; i<len; i++) {
		{
			// setup pointers for each iteration

			key = prtH[i + 1];
			///printf("i=%d , key = %d, prtH=%d\n", i, key, prtH[i]);
			while (prtH[i]>key &&i >= 0)
			{

				prtH[i + 1] = prtH[i];
				//printf("i=%d, prtH[i]=%d, key=%d\n", i, prtH[i], key);
				//if (prtH[i] <= key &&prtH >= header)
				//	prtH[i] = key;
				i--;

			}
			prtH[i + 1] = key;
			// printArray(header, 7);

		}

	}

}


int main() {

	int array[] = { 7,8,5,2,4,6,3 };

	int len = sizeof(array) / sizeof(int);

	sortArray(array, len);
	printf("====ENDOFSORTING===/");
	printArray(array, len);
	return 0;
}