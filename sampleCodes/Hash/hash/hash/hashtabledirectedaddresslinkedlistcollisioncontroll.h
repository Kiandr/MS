#pragma once


#ifndef	HASHTABLEDIRECTEDADDRESSLINKEDLISTCOLLISIONCONTROLL_H_   /* Include guard */
#define HASHTABLEDIRECTEDADDRESSLINKEDLISTCOLLISIONCONTROLL_H_

typedef struct  hashNodeStruct { hashNodeStruct *next; hashNodeStruct *prev; int val; } hashNodeStruct;


void testDirectedAddresshashCollision(void);

#endif // INSERT_H_
