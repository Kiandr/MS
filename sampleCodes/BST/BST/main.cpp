#include "lib.h"
#include "stdio.h"
#include "stdlib.h"


int main() {

	
	node *test = NULL;
    node *testedHeader  = InitHeader(test,120);
	node *testedInsertToRight = Insert(testedHeader, 60);
	node *testedInsertToLeft = Insert(testedHeader, 180);
	node *testedInsertTo45 = Insert(testedHeader, 30);
	node *testedInsertTo15 = Insert(testedHeader, 90);
	node *testedInsertTo130 = Insert(testedHeader, 150);
	node *testedInsertTo210 = Insert(testedHeader, 210);
    node *testedInsertTo310 = Insert(testedHeader, 310);


	node *tesSearch = Search(testedHeader, 15);
	InOrderWalk(testedHeader);



    printf("End of the function !! \n");




	return 0;



};
