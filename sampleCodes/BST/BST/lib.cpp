#include "lib.h"
#include "stdio.h"
#include "stdlib.h"

void HelloWorld()
{
	printf("TEST");

}
 node * InitHeader(node * prtToH, int inVar)
{
	int i = 10;

	node *header = (node*)malloc(sizeof(node));
	header->left = nullptr;
	header->right = nullptr;
	while (i)
	{
		*(header->stringHolder + (10-i) ) = "E";
		i--;
	}
	header->val = inVar;

	return header;
}
 node * Search(node * prtToH, int InNode)
 {
	 // place holder for header
	 node *prt = prtToH;

	 if (prt->val == InNode)
		 return prt;

	 // in order, pre order and post order 
	 if (prt->val >InNode && !(prt->left==NULL))
		return  Search(prtToH->left, InNode);
	 if (prt->val < InNode && !(prt->right == NULL))
		 return Search(prtToH->right, InNode);

	




 }
 node * Insert(node *prtToHead, int inVar) {
 
	 // pointers that are being used.  
	 node *prtToHeader = prtToHead;
	 node *prev = prtToHeader;
	 // Check if the Pointer to the header is still pointing to the existing one
	 if (!(prtToHeader->left == nullptr) && !(prtToHeader->right == nullptr)) {
		 // 
		 if (prtToHeader->val > inVar)
			 Insert(prtToHeader->left, inVar);
		 else if (prtToHeader->val < inVar)
			 Insert(prtToHeader->right, inVar);
	 }
	 else {
		 // Now we are at leaf, check val and add the val 
		 if (prtToHeader->val > inVar)
			 prtToHeader->left = BuildNewNode(inVar);
		 if (prtToHeader->val < inVar)
			 prtToHeader->right = BuildNewNode( inVar);
	 }
	 return prtToHead;
 }
 node * BuildNewNode(int inVar)
 {
	 int i = 10;

	 node *header = (node*)malloc(sizeof(node));
	 header->right = nullptr;
	 header->left = nullptr;
	 while (i)
	 {
		 *(header->stringHolder + (10 - i)) = "E";
		 i--;
	 }
	 header->val = inVar;

	 return header;
 }
 // 1- What is the possiblity of transversing safely?
