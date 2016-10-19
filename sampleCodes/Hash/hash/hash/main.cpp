#include "lib.h"
#include "libPP.h"
#include "iostream"

int main() {

	//serviceHash *serviceCallHash = new serviceHash("t");
	ISService *service = (ISService*)malloc(sizeof(ISService));
	service->print();

	IServiceHashPP *serviceP = new IServiceHashPP();
	serviceP->print();
	return 0;



};