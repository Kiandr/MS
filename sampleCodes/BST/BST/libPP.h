//#include<stdio.h>
//#include<stdlib.h>
//typedef struct lNode {
//	lNode *left;
//	lNode *right;
//	char valChar;
//	int valInt;
//};
//
//
//static lNode *BuildNewNode(lNode *prtSuccessor, char *chVar, int inVar) {
//
//		lNode *newNode = (lNode*)malloc(sizeof(lNode));
//		newNode->valChar = *chVar;
//		newNode->valInt = inVar;
//		newNode->right = NULL;
//		newNode->left = NULL;
//
//		return (lNode*)newNode;
//
//	};
//
//static lNode *findLeaf(lNode *prtToHeader, int inVar) {
//		// Recursive Method
//		// reserved pointer
//		lNode *prev = NULL;
//		while (prtToHeader) {
//			//if (prtToHeader->left != NULL && prtToHeader->right != NULL) {
//			if (prtToHeader->valInt < inVar) {
//				prev = prtToHeader;
//				findLeaf(prtToHeader->right, inVar);
//			}
//			if (prtToHeader->valInt > inVar) {
//				prev = prtToHeader;
//				findLeaf(prtToHeader->left, inVar);
//			}
//			//}
//		}
//		return prev;
//	};
