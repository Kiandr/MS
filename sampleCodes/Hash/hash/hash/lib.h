// basic opeartions of the hash table
#include "malloc.h"
typedef struct HashNode {

	char val[2];
	struct HashNode *next;
}node;

class serviceHash {
private:
	int hashTable[10];
	// head of linked list
	 HashNode *head ;

public:
	// cunstroctore;

	serviceHash() {
		head = (HashNode*)malloc(sizeof(HashNode));
		head->next = NULL;
		*head->val = '\0';
	};

	void hashInsertNode(char *input) {
		if (*input != '\0') {
			if (head != NULL) {

			}
			else { // the header is not inititated
				head = (HashNode*)malloc(sizeof(HashNode));
				*head->val = *input;
				head->next = nullptr;
			}
		}
	};
	void hashSearchNode() {};
	void hashDeleteNode() {};
	void hashPrintNode() {};



};

