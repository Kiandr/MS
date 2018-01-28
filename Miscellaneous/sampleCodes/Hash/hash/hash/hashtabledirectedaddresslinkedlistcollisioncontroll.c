#include "stdio.h"
#include "hashtabledirectedaddresslinkedlistcollisioncontroll.h"

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

	if (*(prtToArrayTable + hashIdex) == NULL) {
		printf("The index [%d]is empty, you can add value %d! \n", hashIdex, aVal);
		*(prtToArrayTable + hashIdex) = aVal;
	}
	else {

		/*
		Author: Kian D.Rad
		Date: July 13th 2017
		README: is there an exising value?
		https://github.com/Kiandr/MS/commit/d996a9f0750dee9f71db160a2f1a900bb4adbb9f
		*/


		/*	if ((*(prtToArrayTable + hashIdex)).type == "LinkedListHeader")
		{
		printf("The value collision detected NO linkedList, go ahead with buildin header ");
		}*/


		printf("Collision occured. Please use collision control method to index %d, with existing val = %d.\n",
			hashIdex, *prtToArrayTable + hashIdex);
	}

}



/*
The following are LinkedList Managament codes; 
*/


hashNodeStruct *AddNewStructNodeEmpty() {
/*
Author: Kian D.Rad
Date:	July 13th 2016
README: Build a struct node associate malloc,
	add next and prev as null and existing valu null too. 

*/



	hashNodeStruct *aNode =  (malloc(sizeof(hashNodeStruct)));
	aNode->next = NULL;
	aNode->prev = NULL;
	aNode->val = NULL;
	return aNode;
}

/*
The following functions are utility methods.
*/


void DirectedAddressHashTablePrint(int *prtToHashArray) {

	int i = 0;

	printf("printing hash table:\n");
	while (prtToHashArray && i<20) {

		printf("[%d] = %d \n", i, *prtToHashArray);
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


	*/
	// Test #1
struct	hashNodeStruct hashArray[20];
	// Build Array with Values null for non-existance value; 
	for (int i = 0; i < 20; i++) {

		hashArray[i] =  *AddNewStructNodeEmpty();
	}
	DirectedAddressHashTableInsert(hashArray, 1);
	DirectedAddressHashTableInsert(hashArray, 2);
	DirectedAddressHashTableInsert(hashArray, 4);

	DirectedAddressHashTablePrint(hashArray);


}
