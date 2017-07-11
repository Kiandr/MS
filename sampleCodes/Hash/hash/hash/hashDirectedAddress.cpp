#include "stdio.h"


/*
Date: 	Jun 19th2017
Author: Kian Davoudi-Rad Engineer-In-Training
Title: 	hashTable Directed Address Implementation
README: This class manages a directed address hash table. This class also manages colusion 
		by "Seperated Chaning".


*/

int  HashFuntion(static int  theNumberToBeInsertedInTheHashTable) {

	/*
	Author:		Kian D.RAD
	Date:		July 10th 2017
	README:		use a simple function method to return a number between 0 to 100 for a N value. 
	ToDO:		NONE
	*/

	int aVal = theNumberToBeInsertedInTheHashTable;
	return ((aVal) / 2);

};
int  DirectedAddressHashTableDelete(static int * table, int *hashCode)
{
	return 0;
}
int  DirectedAddressHashTableSearch(int * table, int  aVal)
{
	return  *(table + aVal);
}

void DirectedAddressHashTableInsert(int *prtToArrayTable, int aVal) {

	/*
	Author:		Kian D.RAD
	Date:		July 11th 2017
	README:		This fuction uses the hash to identify which index the value shuold be inserted. 
				Once, its is identified, the function checks if the index is empty. If not this 
				function will use collision controll, to copy the existing value into a header
				of a linked list, then from that point on, it will be adding to linked list. 
	ToDO:		1- Find the index: 
				2- Check if index is empt or full. 
	
	
	*/
	int hashIdex = HashFuntion(aVal);

	if (*(prtToArrayTable + hashIdex)>=0) {
		printf("The index [%d]is empty, you can add value %d! \n", hashIdex,aVal);
		*(prtToArrayTable + hashIdex) = aVal;
	}
	else {
	
		printf("Collision occured. Please use collision control method to index %d, with existing val = %d.\n", hashIdex,*prtToArrayTable+hashIdex);
	}

}


/*
 The following functions are utility methods. 
*/


void DirectedAddressHashTablePrint(int *prtToHashArray) {

	int i = 0;

	printf("printing hash table:\n");
	while (prtToHashArray && i<20) {
	
		printf("[%d] = %d \n",i,*prtToHashArray);
		i++;
		prtToHashArray++;
	}
	printf("end of print hash table:\n");
}


void testDirectedAddresshashCollision(void)
{

	/*
	Author:		Kian D.RAD
	Date:		July 11th 2017
	README:		functional test
	1- Test to init hashArray and add three values from 0 to 2 indexes. PASSED
	2- Test for collision contorl, if insert index 1, expected is printf and do not add. 
		Result: Did not pass at L52:->  https://github.com/Kiandr/MS/commit/5627b3f4528fd4cdcf7ba9c786b8399142765dc3
		EffortNew: 
	
	*/
	// Test #1
	int hashArray[20];
	// Build Array with Values null for non-existance value; 
	for (int i = 0; i < 20; i++) {
	
		*(hashArray + i) = NULL;
	}
	DirectedAddressHashTableInsert(hashArray, 1);
	DirectedAddressHashTableInsert(hashArray, 2);
	DirectedAddressHashTableInsert(hashArray, 4);

	DirectedAddressHashTablePrint(hashArray);
	
	// Test #2
	printf("Test #2 begins\n");
	DirectedAddressHashTableInsert(hashArray, 2);
	DirectedAddressHashTablePrint(hashArray);
}
