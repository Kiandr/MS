// basic opeartions of the hash table
#include "malloc.h"
#include "iostream"
typedef struct HashNode {
	char *val;
}node;

struct {

	void print() {
		std::cout << "Cunstrocted Structure Initated!"<<std::endl;
	};

	// Operation 1: 
	// Insert, its an O(1) operation,
	// Get Header, newVal and index
	// Analysis: get three vals initated first. 
	// The service is entrierly responsible to logic
	// The main function is responsible managing pointer's address
	bool Insert(HashNode *header, char *val, int index) {
	
		if (!header)
		{
			return 0;
		}

		char *location = (char*)(header->val + (index));
		*location = *val;
		
		printf("%s\n", header->val);
		return 1;
	};
	// Get the header, index and go to that index to put a space character
	bool Del(HashNode *header, int index) {
		// what are the cases? When the header is not initated
		if (!header)
		{
			return 0;
		}
		// identify the location of the index from pointer size 
		char *location = (char*)(header->val + (index));
		char empty[] = " ";
		*location = *empty;
		printf("%s\n", header->val);
		return 1;
	};



}typedef ISService;