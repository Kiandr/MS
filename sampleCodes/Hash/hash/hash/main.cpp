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

	//  this rule applies all the time "index < t"
	service->Insert(header,"O",11);
	service->Del(header, 11);
	std::cout<<service->Search(header,"a");
	return 0;



};