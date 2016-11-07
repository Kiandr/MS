#include "lib.h"

#include<stdio.h>
#include<stdlib.h>

int main() {


	CommonServices *comServ = (CommonServices*)malloc(sizeof(CommonServices));
	BSTService *service = (BSTService*)malloc(sizeof(BSTService));
	lNode *header = NULL;
	header = service->Insert(header, "K", 50);
	service->Insert(header, "I", 30);
	service->Insert(header, "A", 20);
	service->Insert(header, "N", 40);



	return 0;



};