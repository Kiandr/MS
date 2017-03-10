#include "stdio.h"



void *partition(int *prt,int len){
	
	// pick a pivote
	int *pivote = *prt;
	int *prtTransvers = prt;
	int *prtCardOpen; 

	
	while (*prtTransvers>=0)
{

	if (*prt>*prtTransvers)
	{
	prtCardOpen = prtTransvers;
	printf(" -HEX = [%d]->[ %d ] ", prtTransvers,*prtTransvers);
	printf(" PrtOpenCard is  -HEX = [%d]->[ %d ] ", prtCardOpen,*prtCardOpen);
	}
	printf("\n");
	prtTransvers++;
}
	
	
	
	
};

int main(){

int array[]={3,1,4,1,5,9,2,6,5,3};
int *prt = array;

partition(prt,10);

// for (int i = 0; i<10; i++)
// {	printf(" - %d - ",*(int*)prt);
// 	prt++;
// }
printf("\n");
	return 0;
}
