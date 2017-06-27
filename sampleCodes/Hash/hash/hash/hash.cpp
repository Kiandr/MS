#include "hash.h"
#include "stdio.h"
/*
Date: 	Jun 19th2017
Author: Kian Davoudi-Rad Engineer-In-Training
Title: 	hashTable Directed Address Implementation
README: the size of hashtable should be the same as the actual table.


*/
#pragma HashTable Directed Addres
int hash(static int  aVal) {

	/*
	README:
	Each newVal will be sent to hashFuntion to obtain an index.
	This hash function is not managing the collision, also this
	hash function does not check for null values.

	*/

	return ((aVal) / 2);

}
void DirectedAdressHashTableInsert(static int * table, int  newVal) {

	/*
	README:
	Each newVal will be sent to hashFuntion to obtain an index.
	This hash function is not managing the collision, also this
	hash function does not check for null values.

	*/

	int *prtToHead = table;
	int *prtToIndex = prtToHead + hash(newVal);
	*prtToIndex = newVal;

};
int DirectedAddressHashTableDelete(static int * table, int *hashCode)
{
	return 0;
}
int  DirectedAddressHashTableSearch(int * table, int  aVal)
{
	return  *(table + aVal);
}
void TestHashFunction() {

	int inputValue = 10;


	int result = hash(inputValue);
	if (result * 2 == inputValue)
		printf("Success TestFunction HashCode Generation");
	else
		printf("Failed hash code value; returned %d", result);
}
void testInsertFunction(void)
{

	int table[10];
	DirectedAdressHashTableInsert(table, 4);
	for (int i = 0; i < 10; i++)
	{
		printf("index[%d] = [%d]\n",i,table[i]);
	}
}
void testSearchFunction() {



}

