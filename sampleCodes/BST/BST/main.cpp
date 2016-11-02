#include "lib.h"
#include "libPP.h"
#include "iostream"

int main() {

	//serviceHash *serviceCallHash = new serviceHash("t");
	LService *lService = (LService*)malloc(sizeof(LService));
	CommonServices *comServ = (CommonServices*)malloc(sizeof(CommonServices));
	char t = 's';
	lNode *header = comServ->BuildAHeader(&t,50);
	lService->Insert(header, "I", 10);
	lService->Insert(header, "A", 1);
	lService->Insert(header, "N", 5);
	lService->Insert(header, "D", 2);
	return 0;



};