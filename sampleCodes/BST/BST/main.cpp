#include "lib.h"
#include "libPP.h"
#include "iostream"

int main() {

	//serviceHash *serviceCallHash = new serviceHash("t");
	LService *lService = (LService*)malloc(sizeof(LService));
	CommonServices *conserv = (CommonServices*)malloc(sizeof(CommonServices));
	lNode *header = (lNode*) malloc(sizeof(lNode));
	char t = 's';
	header = lService->Insert(header, &t, 1);
	int test = 0;


	return 0;



};