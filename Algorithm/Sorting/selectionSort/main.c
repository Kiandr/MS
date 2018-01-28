#include "stdio.h"


/*
Author: Kian D.Rad
Date Nov 14th 2017
ReadMe: selection sort algorithm for int array
*/
void selectionSortInt( int *header, int l){

	int *key = header; 
	int *prtH = header;
	
	// first iteration
	for (int j=0; j<l; j++){
		int i = j;
		key = &prtH[j];
		while (prtH[i]>prtH[i+1] && i<l)
			i++;

		//if (prtH[i]>prtH[i+1]){
		int temp = *key;
		*key = prtH[i];
		prtH[i]=temp;
		//}
	}

	
}

/*
Author: Kian D.Rad
Date Nov 14th 2017
ReadMe: selection sort algorithm for char array
*/
void selectionSortChar( char *header){}


/*
Author: Kian D.Rad
Date Nov 14th 2017
ReadMe: int main, sorts two arrays. Int anc Char array using selection sort algortihm
*/
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(int);
    printArray(arr, n);
    selectionSortInt(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
	
	return 0;
}