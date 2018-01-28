#include "stdio.h"

void	Merge(int *head, int lowIndex, int midd ,int hiIndex){
	
	// temp array 
	int temp [hiIndex-lowIndex+1];
	// left index iterator
	int i = lowIndex;
	// right index interator
	int j = midd +1;
	// index for tempArray 
	int k=0;
	int interator = 0;
	int lenTemp = hiIndex-lowIndex+1;
	
	// actual merge happens here. 
	while (i<=midd && j<=hiIndex){
		if (head[i]<=head[j])
			temp[k++] = head[i++];
		else if (head[j]<=head[i])
			temp[k++] = head[j++];
		}
		// copy rest of the array left 
		while (i<=midd){
				temp[k++] = head[i++];
		}

		// copy rest of the array right 
		while (j<=hiIndex){
			temp[k++] = head[j++];
		}
		
	//	copy temp array into new array
			for (k=0, i=lowIndex; i<=hiIndex;++i,++k)
				head[i]=temp[k];
			
	//		while (interator< lenTemp)
	//		{
		//		head[interator] = temp [interator];
			//	interator++;
			//}
		
	

	

}

void	MergeSort(int *head, int lowIndex, int hiIndex){
	

	int midd = (lowIndex+hiIndex)/2;

	
	if (lowIndex<hiIndex){
	MergeSort(head, lowIndex, midd);
	MergeSort(head, midd+1, hiIndex);
	Merge   (head, lowIndex,  midd , hiIndex);
//	printf("=========\n");
//	printf("header = %d\n",*head);
//	printf("[%d ]",head[lowIndex]);
//	printf("[%d]",head[midd]);
//	printf("[ %d]",head[hiIndex]);
//	printf("len = %d\n",hiIndex-lowIndex);
//	printf("=========\n");


	}

	
	
}


int main(){

	int array[]={9,8,7,6,5,4,3,2,1};
	int len = sizeof(array)/sizeof(int);
	
	MergeSort(array,0,sizeof(array)/sizeof(int)-1);
	
	
	for (int i=0;i<len;i++)
		printf("%d-",array[i]);
	printf("=========\n");
	return 0;
};
