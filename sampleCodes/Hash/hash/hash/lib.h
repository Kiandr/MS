// basic opeartions of the hash table
#include "malloc.h"
#include "iostream"
typedef struct HashNode {
	char *val;
}node;

struct {

	void print() {
		std::cout << "Cunstrocted Structure Initated!";
	};

	// Operation 1: 
	// Insert, its an O(1) operation,
	// Get Header, newVal and index
	bool Insert(HashNode *header, char *val, int index) {
	
		if (!header)
		{
			return 0;

		}
		char *location = (char*)(header->val + (4 * index));
			*location = *val;
		printf("%s", header->val);
		return 1;
	};




}typedef ISService;