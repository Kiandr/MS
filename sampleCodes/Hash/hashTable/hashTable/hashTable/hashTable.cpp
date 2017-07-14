#include "hashTable.h"
#include "stdio.h"
void HelloWorld()
{
	/*
	Author: Kian D.Rad
	Data:	July 14th 2017
	README: 
		1- Init array type node and assing null to the each memeber. PASSED
	*/

	// define an array of type node
	static node DirectedArrayListNodeType[10];

	// use a prt to iterate within the array
	node *prtToH = DirectedArrayListNodeType;

	// print the array
	printf(" START OF Test 1 \n");
	for (int i = 0; i < 10; i++) {

		// Navigator via Directed Access
		//*prtToH = DirectedArrayListNodeType[i];
		// Navigator via pointer
		prtToH = prtToH+i;
		node *t = NULL;

		prtToH->next = NULL;
		prtToH->prev = NULL;
		prtToH->val = 10;

		printf("index [%d] contains value [%d]\n",i,(prtToH)->val);
		
	}
	printf(" END OF Test 1 \n");
}
