
#ifndef	HASHDIRECTEDADDRESS_H_   /* Include guard */
#define HASHDIRECTEDADDRESS_H_

struct hashNodeStruct { hashNodeStruct *next; hashNodeStruct *prev; int val; } hashNodeStruct;


void testDirectedAddresshashCollision(void);

#endif // INSERT_H_