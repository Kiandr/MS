// basic opeartions of the hash table
#include "malloc.h"
#include "iostream"
typedef struct lNode {
	lNode *next;
	lNode *successor;
	lNode *left;
	lNode *right;
	char valChar;
	int valInt;
}lnode;
typedef struct tNode {
	lNode *next;
	lNode *successor;
	lNode *left;
	lNode *right;
	char valChar;
	int valInt;
}tnode;
struct {

	lNode *BuildAHeader(char *chVar, int inVar) {

		static lNode *newNode = (lNode*)malloc(sizeof(lNode));
		newNode->valChar = *chVar;
		newNode->valInt = inVar;
		newNode->successor = NULL;
		// Forgot this part of the code
		// Left and Right should be NULL
		newNode->left = NULL;
		newNode->right = NULL;
		return (lNode*)newNode;

	};


	lNode *BuildNewNode(lNode *prtToNode,char *chVar, int inVar) {

		static lNode *newNode = (lNode*)malloc(sizeof(lNode));
		newNode->valChar = *chVar;
		newNode->valInt = inVar;
		newNode->right = NULL;
		newNode->left = NULL;
		newNode->successor = prtToNode;
		return (lNode*)newNode;

	};

	lNode *findLeaf(lNode *prtToHeader,int inVar) {
		// Recursive Method
		// reserved pointer
		lNode *prev = NULL;
		while (prtToHeader) {
			//if (prtToHeader->left != NULL && prtToHeader->right != NULL) {
				if (prtToHeader->valInt < inVar) {
					prev = prtToHeader;
					findLeaf(prtToHeader->right, inVar);
				}
				if (prtToHeader->valInt > inVar) {
					prev = prtToHeader;
					findLeaf(prtToHeader->left, inVar);
				}
			//}
		}
		return prev;
	};
		


}typedef CommonServices;
// LinkedList Operatioin
struct {
	CommonServices *comServ;
	// Header should be initated in main function;
	// Based on this link: http://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/
	lNode *Insert(lNode *header, char *chVar, int inVar) {
		// pointers that are being used.  
		lNode *prtToHeader = header;
		lNode *prev = prtToHeader;
		// Check if the Pointer to the header is still pointing to the existing one
		if ((prtToHeader->left != NULL) && (prtToHeader->right != NULL)) {

			// 
			if (prtToHeader->valInt > inVar)
				Insert(prtToHeader->left, chVar, inVar);
			else if (prtToHeader->valInt < inVar)
				Insert(prtToHeader->right, chVar, inVar);
		}

		// Now we are at leaf, check val and add the val 
		if (prtToHeader->valInt > inVar)
			prtToHeader->left = comServ->BuildNewNode(prtToHeader,chVar, inVar);
		if (prtToHeader->valInt < inVar)
			prtToHeader->right = comServ->BuildNewNode(prtToHeader, chVar, inVar);

		return prtToHeader;

	};

	void Search() {};
	void Delete() {};
	void Min() {};
	void Max() {};
	void Successor() {};
	void PreDeccessor() {};


}typedef LService;
struct {


}typedef TSService;

