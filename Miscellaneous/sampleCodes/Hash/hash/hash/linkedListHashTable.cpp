#include "stdio.h"
// Malloc library 
#include "stdlib.h"
#include "linkedListHashTable.h"

#pragma
/*
Author: Kian D.Rad
Date: Jun20th2017
README: Implementation of hashtable via linkedlist 
*/

/* === === === Private Data Strucutre === === === */ 
typedef struct hashNode{

	int intKey;  // Acutally I dont know what is the impact of having this as pointer VS actual value. 
//	char charString[20];

	hashNode * prev;
	hashNode * next;

} hashNode;

/* === === === Private Utility === === === */

// Hash Function
int hashFunction(int aval) {
	/*
	Author:		Kian D.RAD
	Date:		Jun20th2017
	REAADME:	Takes a key and returns the index of that string in the table
	ToDO:		Add a dynamic function that is going to enable each to index be produced
	*/

	int newIndexToLocationOfANodeInHashTable = 2;
	return newIndexToLocationOfANodeInHashTable;

}


// build a hash Node 
hashNode *initANewHashnode() {
	/*
	Author:		Kian D.RAD
	Date:		Jun20th2017
	README:		Build a new node initializer
	ToDO:		I dont know how to carry on a Char Pointer without loosing the malloc address
	during life type of the program. Will get back to it later.
	*/
	hashNode *newNode = (hashNode*)malloc(sizeof(hashNode));
	newNode->intKey = 0;
	newNode->next = (hashNode*)malloc(sizeof(hashNode));
	
	return newNode;
};


// Init hash node with memeber
hashNode *initANewHashnodewithValue(int aVal, char* aString) {
	/*
	Author:		Kian D.RAD
	Date:		Jun20th2017
	README:		Build a new node initializer with val and a string.
	ToDO:		I dont know how to carry on a Char Pointer without loosing the malloc address
	during life type of the program. Will get back to it later.
	*/


	hashNode *newNode = (hashNode*)malloc(sizeof(hashNode));

	if (aVal)
		newNode->intKey = aVal;

	else
		newNode->intKey = 0;

	return newNode;

};


// PrintSerializer 
void printALinedListNode(hashNode* prtAHashNode) {
	hashNode *prtH = prtAHashNode;
	if (prtH != nullptr) {

		printf("=== Begining of print  a HashNode			\n");
		printf("=== hashNode this prt   =  %d      		\n", prtH);
		printf("=== hashNode int Val	=  %d      		\n", prtH->intKey);
		printf("=== hashNode next prt   =  %d      		\n", prtH->next);
		printf("=== hashNode next prev  =  %d      		\n", prtH->prev);
		printf("=== END		 of print  a HashNode			\n");

	}


}


// Print a linkedList
void printALinkedListNode(hashNode *prtToHeader) {
	/*
	Author: Kian D.Rad
	Date:	Jun22nd 2017
	ReadMe: Print a linkedlist, uses only next prt, and while if next node is valid prt.
	Note:	Due to VisualStudio IDE, prtH=prtH->next is casted to a hashNode, its not ne-
	cessary, if VS is not used as IDE.
	*/
	hashNode *prtH = prtToHeader;
	if (prtH != nullptr) {

		while (prtH->next != nullptr) {
			printALinedListNode(prtH);
			prtH = (hashNode*)prtH->next;
		}
	

	}


}


// Build init hash table
hashNode *initHashTableWithLengthOfHashFunction(int n) {
	/*
	Author:		Kian D.RAD
	Date:		Jun22nd2017
	REAADME:	Theory says, that space of the hash function is larg, thus, return of hash function is an address
	to index of linked list. This algorithm garantees O(1) search complexity. Thus, I undrestand that
	the hash table should have been initated already.
	The reason that prtToHead is a pointer is due to the fact that the address of memeory does not die,
	i guess :-) thus, as long as the memory exists in the cash the pointer should be valid. Or Not :-0

	Bugs: I forgot to linked the nodes. I forgot to put transvers in the while loop, multiple issues. 
	*/

	// How to build a linked list: 
	// build a header. 
	hashNode* header = (hashNode*)malloc(sizeof(hashNode));
	header->intKey = 0;
	header->next = NULL;
	header->prev = NULL;


	// you need a prt to transvers within the linkedList
	hashNode *prtH = header;
	// n>1 because you have already created one node. The header
	while (n > 0)
	{
		n--;
		// Build current prt
		prtH->intKey = 0;

		// Build next prt
		prtH->next = (hashNode*)malloc(sizeof(hashNode));
		prtH->next->prev = prtH;
		prtH->next->next= NULL;
		prtH->next->intKey = NULL;
		// Go to next only when the next one has been created built. 
		prtH= prtH->next;
		
	}

	return header;
}

/* === === === Public Members === === === */

// Public Members
void LinkedListInsertHashTable(hashNode* header, int newIncomingVal) {
	/*
	Author: Kian D.Rad
	Date: Jun20th2017
	README: take pointer to the linkedlist head and insert a new value into a new node then append node
	into the header, the location of the node is going to be the defined by the hash table.
	Expectaion is that the address is going to be identify how many nodes the new node should be
	created in regards to the head.
	
	Wihle 
	*/
	hashNode *prtH = header;
	int hashIndex = hashFunction(newIncomingVal);
	int i = 0;
	while ( i <= hashIndex)
	{
		i++;
		prtH = prtH->next;
		if (i == hashIndex )
		{
			prtH->intKey = newIncomingVal;
		}
	}

}
int  LinedListSearchHashTable(hashNode* header, int indexReturedFromHashFunction) {

	hashNode *prtH = header;
	int hashIndex =indexReturedFromHashFunction;
	int i = 0;
	while (i <= hashIndex)
	{
		i++;
		prtH = prtH->next;
		if (i == hashIndex)
		{
			return prtH->intKey;
		}

	}
	return 0;
};



/* === === === Public Testers === === === */
void testInithashFunction(int length)
{

	hashNode *prtToHead = initHashTableWithLengthOfHashFunction(length);

	printALinkedListNode(prtToHead);
	LinkedListInsertHashTable(prtToHead,20);
	printALinkedListNode(prtToHead);
	int t = LinedListSearchHashTable(prtToHead, 2);
	printf("Search Resault =-> %d",LinedListSearchHashTable(prtToHead, 2));

}


/* === === === Collision Controll=== === === */
// The following are the three collision controll functions: 

void ChainedHashedInsert(hashNode hashTableHeader, int aKeyValue) {

	/*
	Author: Kian D.Rad
	Date: Jun 26th 2017
	Notes: Hash chanined controller. Insert an x value at the HEAD of the linked list
	The linkedlist will add the new node in the same hashTable slot.
	*/
}

void ChainedHashedSearch(hashNode * hasTableHeader, int aKeyValue) {
	/*
	Author: Kian D.Rad
	Date: Jun 26th 2017
	Notes:
	*/
}

void ChangedHashedDelete(hashNode *hashTableHeader, hashNode *aHashNode) {
	/*
	Author: Kian D.Rad
	Date: Jun 26th 2017
	Notes:
	*/
}