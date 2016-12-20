#include "lib.h"
#include "stdio.h"
#include "stdlib.h"


int main() {

	
	node *test = NULL;
	node *testedHeader  = InitHeader(test,100);
	node *testedInsertToRight = Insert(testedHeader, 160);
	node *testedInsertToLeft = Insert(testedHeader, 30);
	node *testedInsertTo45 = Insert(testedHeader, 45);
	node *testedInsertTo15 = Insert(testedHeader, 15);
	node *testedInsertTo130 = Insert(testedHeader, 130);
	node *testedInsertTo210 = Insert(testedHeader, 210);

	node *testerNode = BuildNewNode(15);

	node *tesSearch = Search(testedHeader, 15);






	return 0;



};