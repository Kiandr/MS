// basic opeartions of the hash table
#ifndef  LIB_H_
#define LIB_H_
typedef  struct node {
	node *right;
	node *left;
	char *stringHolder[10];
	int val;
};
//extern void HelloWorld();
extern node *InitHeader( node *prtToH, int inVar);
//extern node *Seach(node *prtToH);
extern node *Insert(node * portToH, int val);
extern node * BuildNewNode(int val);
#endif // LIB_H_


