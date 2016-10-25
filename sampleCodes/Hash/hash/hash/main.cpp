#include "lib.h"
#include "libPP.h"
#include "iostream"

int main() {

	//serviceHash *serviceCallHash = new serviceHash("t");
	ISService *service = (ISService*)malloc(sizeof(ISService));
	service->print();

	// Header
	HashNode *header = (HashNode*)malloc(sizeof(HashNode));
	char t[] = "KianDavoudi";
	header->val = t;

	IServiceHashPP *serviceP = new IServiceHashPP();
	//serviceP->print();
	service->Insert(header,"O",1);
	return 0;



};