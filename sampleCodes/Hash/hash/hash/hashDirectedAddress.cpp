#include "hash.h"
#include "stdio.h"
#include "stdlib.h"
#include "hashDirectedAddress.h"
/*
Date: 	Jun 19th2017
Author: Kian Davoudi-Rad Engineer-In-Training
Title: 	hashTable Directed Address Implementation
README: This class manages a directed address hash table. This class also manages colusion 
		by "Seperated Chaning".


*/

int  HashFuntion(static int  theNumberToBeInsertedInTheHashTable) {

	/*
	Author:		Kian D.RAD
	Date:		July 10th 2017
	README:		use a simple function method to return a number between 0 to 100 for a N value. 
	ToDO:		NONE
	*/

	int aVal = theNumberToBeInsertedInTheHashTable;
	return ((aVal) / 2);

};
int  DirectedAddressHashTableDelete(static int * table, int *hashCode)
{
	return 0;
}
int  DirectedAddressHashTableSearch(int * table, int  aVal)
{
	return  *(table + aVal);
}
void TestHashFunction() {

	/*int inputValue = 10;


	int result = hash(inputValue);
	if (result * 2 == inputValue)
		printf("Success TestFunction HashCode Generation");
	else
		printf("Failed hash code value; returned %d", result);*/
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

void testDirectedAddresshashCollision(void)
{

}
