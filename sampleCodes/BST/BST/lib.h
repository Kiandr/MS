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
		newNode->successor = nullptr;
		newNode->next = nullptr;
		return (lNode*)newNode;

	};


	lNode *BuildNewNode(lNode *prtToNode,char *chVar, int inVar) {

		static lNode *newNode = (lNode*)malloc(sizeof(lNode));
		newNode->valChar = *chVar;
		newNode->valInt = inVar;
		newNode->next = nullptr;
		newNode->successor = prtToNode;
		return (lNode*)newNode;

	};

	lNode *findLeaf(lNode *prtToHeader,int inVar) {
		// Recursive Method

		while (prtToHeader) {
			//if (prtToHeader->left != NULL && prtToHeader->right != NULL) {
				if (prtToHeader->valInt < inVar) {
					prtToHeader = prtToHeader->right;
				}
				if (prtToHeader->valInt > inVar) {
					prtToHeader = prtToHeader->left;
				}
			//}
		}
		return prtToHeader;
	};
		


}typedef CommonServices;



struct {
	CommonServices *comServ;
	// Header should be initated in main function;

	int Insert(lNode *header, char *chVar, int inVar) {
		// fill the header 
		lNode *prtToHeader = header;
		lNode *prev = prtToHeader;
		int resultOfFunction = 0;
		if (header != nullptr)
		{

			// continue while searching to for the node


				// find leave (prtToHeader)
			prev = comServ->findLeaf(prtToHeader, inVar);

			//	// if prtHeader->val<inVar
			//	if (prtToHeader->valInt < inVar) {
			//		prev = prtToHeader;
			//		prtToHeader = prtToHeader->right;
			//	}
			//	// go Right 
			//	// ifelse prtHeader->val>inVar
			//	// go Left
			//	if (prtToHeader->valInt > inVar) {
			//		prev = prtToHeader;
			//		prtToHeader = prtToHeader->left;
			//	}

			//}

			// Found the child node, addAnewNode int it
			///
			//if (prev->valInt < inVar) {
			//	// if prtHeader->val<inVar
			//	// Add to Right 
			//	prev->right = comServ->BuildNewNode(prev, chVar, inVar);
			//}
			//// ifelse prtHeader->val>inVar
			//if (prev->valInt < inVar) {
			//	// Add to Left
			//	prev->left = comServ->BuildNewNode(prev, chVar, inVar);
			//	///
			//}
			//// Successfull insertion
			//resultOfFunction = 1;

		}
		// return result of insertion 
		return resultOfFunction;

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

