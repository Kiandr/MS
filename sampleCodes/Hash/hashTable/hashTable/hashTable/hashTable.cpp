#include "hashTable.h"
#include "stdio.h"
#include "stdlib.h"

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


node* DirectedAccessHashTableInsert(node * prtToHashTableArray, int aVal) {
	/*
	Author: Kian D.Rad
	Data:	July 20th 2017
	README:	This is an insert on LinkedList function
	ToDo:
	Required: The array should be initialized before, with node objects. So when 
				the user adds into the header, its gonna be avaliable. 
	1- getIndex in the array from hash function
	2- insertIntoThatIndex.
	*/
	node * prtH = prtToHashTableArray;

	// test and debugging 
	int  indexedNode = hash(aVal);
	indexedNode = indexedNode * sizeof(node);
	// this is a case that we assure that header is null. Because next is NULL, and prev is also NULL
	if (((prtToHashTableArray + indexedNode)->next == NULL) && ((prtToHashTableArray + indexedNode)->prev == NULL)) {
		prtToHashTableArray->val = aVal;

		// double check next is empy, because that should be. 
		prtToHashTableArray->next = NULL;
		prtToHashTableArray->prev = NULL;
	}
	// this is the case that we assure header is not null. This means, that the next node exists thus. 
	// header-> prev is always null, but header->next should not be. That should be a valid pointer, a valid interger and 
	// a valid address of memory. The next nude should have a prev as this node, next either empty or next. The content may vary, 
	// may contain 0. 
	else if (((prtToHashTableArray + indexedNode)->next != NULL) && ((prtToHashTableArray + indexedNode)->prev == NULL)) {
	// Now we have to seek the last node of the linked list. 
		node *prt = prtToHashTableArray;
		while (prt->next) {
			prt = prt->next;
		}
		prt->next =(node*) malloc(sizeof(node));
		prt->next->next = NULL;
		prt->next->prev = prt;
		prt->next->val = aVal;
		
	}


	return prtToHashTableArray;

};


void HelloWorld()
{
	/*
	Author: Kian D.Rad
	Data:	July 14th 2017
	README:	This method init the array of struct node with null vals 
	ToDo: 
		1- Init array type node and assing null to the each memeber. PASSED
		2- Test 2: add the val to table, transvers in node linkedlist. PASSED July 21st 2017
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
		//prtToH = prtToH+i;
		node *t = NULL;


		// OR use Array
		/*
		DirectedArrayListNodeType[i].next = NULL;
		DirectedArrayListNodeType[i].prev = NULL;
		DirectedArrayListNodeType[i].val = 100;
		*/

		(prtToH+i)->next = NULL;
		(prtToH+i)->prev = NULL;
		(prtToH+i)->val = 100+i;

		printf("index [%d] contains value [%d]\n",i, DirectedArrayListNodeType[i].val);
		
	}


	printf(" END OF Test 1 \n");



	// Test2
	printf(" START OF Test 2 \n");

	DirectedAccessHashTableInsert(prtToH,1);
	

	for (int i = 0; i < 10; i++) {

		printf("index [%d] contains value [%d]\n", i, DirectedArrayListNodeType[i].val);

	}


	printf(" END OF Test 2 \n");




	// Test3
	// The issue is that it seems that the transverse in the first arry is not working. 
	/*
	node array[10];
	prt = arry;
	prt+x =<<<< is broken. 
	*/

	printf(" START OF Test 3 \n");

	DirectedAccessHashTableInsert(prtToH, 2);


	for (int i = 0; i < 10; i++) {

		printf("index [%d] contains value [%d]\n", i, DirectedArrayListNodeType[i].val);

	}


	printf(" END OF Test 3 \n");









}


