#pragma

#ifndef	HASH_H_   /* Include guard */
#define HASH_H_

int hash(static int * aVal);
void DirectedAdressHashTableInsert(static int *table, int newVal);
int DirectedAddressHashTableDelete(static int * table, int *hashCode);
int DirectedAddressHashTableSearch(static int * table, int aVal);
void TestHashFunction();
void HelloWorld(void);
void testInsertFunction(void);

#endif // INSERT_H_