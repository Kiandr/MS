// basic opeartions of the hash table
#include "malloc.h"
#include "iostream"
typedef struct lNode {
	lNode *next;
	lNode *prev;
	char valChar;
	int valInt;
}lnode;
typedef struct tNode {
	lNode *next;
	lNode *prev;
	char valChar;
	int valInt;
}tnode;

struct {

	lNode *BuildAHeader(char *chVar, int inVar) {

		static lNode *newNode = (lNode*)malloc(sizeof(lNode));
		newNode->valChar = *chVar;
		newNode->valInt = inVar;
		newNode->prev = nullptr;
		newNode->next = nullptr;
		return (lNode*)newNode;

	};


}typedef CommonServices;



struct {
	CommonServices *Comserv;

	// Common tools:
	//lNode *BuildAHeader(char *chVar, int inVar) {

	//	lNode *newNode = (lNode*)malloc(sizeof(lNode));
	//	newNode->valChar = *chVar;
	//	newNode->valInt = inVar;
	//	newNode->prev = nullptr;
	//	newNode->next = nullptr;
	//	return (lNode*)newNode;

	//};

	lNode *Insert(lNode *header, char *chVar, int inVar) {
		// fill the header 
		lNode *prt = header;
		if (header != nullptr)
		{
			
			while (prt->next != nullptr)
				prt = prt->next;

		}

		// else build the header and reaturn the location
		// location of header
		header = Comserv->BuildAHeader(chVar, inVar);
		return header;

	};

	void Search() {};
	void Delete() {};
	void Min() {};
	void Max() {};
	void Successor() {};
	void PreDeccessor() {};


}typedef LService;

struct {


}typedef TSService;

