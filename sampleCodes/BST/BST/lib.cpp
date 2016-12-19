#include "lib.h"
#include "stdio.h"
#include "stdlib.h"

void HelloWorld()
{
	printf("TEST");

}

 node * InitHeader(node * prtToH)
{
	int i = 10;

	node *header = (node*)malloc(sizeof(node));
	header->left = NULL;
	header->left = NULL;
	while (i)
	{
		*(header->stringHolder + (10-i) ) = "E";
		i--;
	}
	header->val = 0;

	return header;
}
