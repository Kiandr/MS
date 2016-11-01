#include "lib.h"
#include "libPP.h"
#include "iostream"

int main() {

	//serviceHash *serviceCallHash = new serviceHash("t");
	LService *lService = (LService*)malloc(sizeof(LService));
	CommonServices *comServ = (CommonServices*)malloc(sizeof(CommonServices));
	char t = 's';
	lNode *header = comServ->BuildAHeader(&t,47);
	lService->Insert(header, "I", 10);
	return 0;



};