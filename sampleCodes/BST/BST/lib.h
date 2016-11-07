// basic opeartions of the hash table
#include<stdio.h>
#include<stdlib.h>
typedef struct lNode {
	lNode *left;
	lNode *right;
	char valChar;
	int valInt;
};

typedef struct CommonServices {

	static lNode *BuildNewNode(lNode *prtSuccessor,char *chVar, int inVar) {

	   lNode *newNode = (lNode*)malloc(sizeof(lNode));
		newNode->valChar = *chVar;
		newNode->valInt = inVar;
		newNode->right = NULL;
		newNode->left = NULL;

		return (lNode*)newNode;

	};

	static lNode *findLeaf(lNode *prtToHeader,int inVar) {
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
	


} ;
// LinkedList Operatioin
typedef struct BSTService {

	/*Insert function*/
	lNode *Insert(lNode *header, char *c, int i) {
		/*Build header*/
		if (header == NULL) return CommonServices::BuildNewNode(header, c, i);

		/*else go down the tree*/
		if (i < header->valInt)
			header->left = Insert(header->left, c, i);
		else if (i > header->valInt)
			header->right = Insert(header->right,c,i);

		return header;

	
	};

};

