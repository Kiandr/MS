#include "hashTable.h"
#include "stdio.h"
#include"stdlib.h"



// 
int hash(int aVal) {

	/*
	Author: Kian D.Rad
	Data:	July 14th 2017
	README:	This method is hash function, returns an index based on input
	ToDo:
	*/


	return (aVal / 2);

}




node *AppendNewNode(node* incomingNode, int aVal) {
	/*
	Author: Kian D.Rad
	Data:	July 14th 2017
	README:	This is an insert new new function
	ToDo:
	1- get the node, allocate memory to it
	2- this.x->prev->next = this.x allocated pointer from prev to this one;
	3- this.x->next = NULL
	4- this.x->val = aVAl;
	5- this.x->prev = prev;

	retrun success

	*/

	node *aNode = (node*)(malloc(sizeof(node)));
	aNode->next = NULL;
	aNode->prev = NULL;
	aNode->val = aVal;
	incomingNode = aNode;
	return incomingNode;


}

node* LinkedListHashInsert(node *nodeToBeInserted, int aVal) {
	/*
	Author: Kian D.Rad
	Data:	July 14th 2017
	README:	This is an insert on LinkedList function
	ToDo:
	1- Get prtToHeader, go to Header
	2- if the header next is null, insert value here.
	3- if header-> next is not null, then go to the end of linkedList
	4- insert the value here, and add prev->next to malloc of this new val
	ToDo:
	*/
	node *prtToH = nodeToBeInserted;

	node *prev = prtToH;

	while (prtToH) {

		if (prtToH->next != NULL)
		{
			prev = prtToH;
			prtToH = prtToH->next;
		}
		else {
		prtToH = 	AppendNewNode(prtToH, aVal);
		
		//prtToH->next->prev = prtToH;
		return prtToH;
		}
	}

	return prtToH;
};


void DirectedAccessHashTableInsert(node * prtToHashTableArray, int aVal) {

	node * prtH = prtToHashTableArray;

	// test and debugging 
	node * indexedNode = prtH + hash(aVal);

	indexedNode = LinkedListHashInsert(indexedNode, aVal);

};




void HelloWorld()
{
	/*
	Author: Kian D.Rad
	Data:	July 14th 2017
	README:	This method init the array of struct node with null vals 
	ToDo: 
		1- Init array type node and assing null to the each memeber. PASSED
		2- Test 2: add the val to table, transvers in node linkedlist
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
		prtToH->val = 0;

		printf("index [%d] contains value [%d]\n",i,(prtToH)->val);
		
	}


	printf(" END OF Test 1 \n");



	// Test2
	printf(" START OF Test 2 \n");

	DirectedAccessHashTableInsert(prtToH,1);
	for (int i = 0; i < 10; i++) {

		printf("index [%d] contains value [%d]\n", i, (prtToH)->val);

	}


	printf(" END OF Test 1 \n");

}


