//
//  main.m
//  hashDirectedAddress
//
//  Created by Kian Davoudi-Rad on 2017-10-03.
//  Copyright © 2017 Kian. All rights reserved.
//
#define INT2VOIDP(i) (void*)(uintptr_t)(i)

#import <Foundation/Foundation.h>
#include "stdio.h"


/*
 * Auhtor: Kian D.Rad
 * Date: Oct 3rd 2017
 * ReadMe: Basic data sctructur for a has function. There is a hash index and hash data.
 */
typedef struct node{

    char * data;
    int key;
    struct node* prev;
    struct node* next;

}node;



/*
 * Author: Kian D.Rad
 * Date: Oct3rd2017
 * ReadMe: This is a simpel function, this could be very well desinged. For now I am using a simple and known function.
 */

int hashCode(int key){
    return key * 1;
}




/*
 * Author: Kian D.Rad
 * Date: Oct3rd2017
 * ReadMe:
 * This function must initalize the array, becuase its a hash array. The U is being defined by the hash function. That defines how many iteams shall be in the array.
 * the key is the index of the array, that could be used to be searched. This search is being taken place upon retrival of the hash value from hash method.
 */
node* initHeader(int len) {

    node * header = (node*) malloc(sizeof(node*));

    node *prtH = header;
    int n = len;
    int i = 1;
    node* prtPrev = NULL;

    while (n){

        prtH->key = i;
        prtH->data = NULL;
        prtH->prev = prtPrev;
        prtH->next =  (node*) malloc(sizeof(node*));;
        prtH->next->prev = prtH;
        // Keep track of the prev pointer. Debugger!
        printf(" prtH = %p | prtH->key=%d |   prtH->next=%p, prtH->prev=%p\n", prtH, prtH->key, prtH->next, prtH->prev);
        prtPrev = prtH;
        prtH=prtH->next;
        i++;
        n--;
    }

    return header;
}




/*
 * Author: Kian D.Rad
 * Date: Oct3rd2017
 * ReadMe:
 *
 */
bool insertHash (node *header, node *aNode){

    node *prtH = header;
    if (!header)
        return 0;
    else {
        /*
         this method will tell you how many nodes do you have to move forward.
         */
       int index = hashCode(aNode->key);

        while (prtH->key != index && prtH->next !=NULL)
        {
            prtH = prtH->next;

        }
        if (prtH->next == NULL)
            return 0;
        else if (prtH->key == index) {
            int l =0;
            char *prtN = aNode->data;
            while (*prtN != '\0')
            {
                l++;
                prtN++;
            }

            prtH->data = (char*)malloc(sizeof(char)*l);
            char *prtD = prtH->data;
            prtN = prtN-l;
            while (*prtN != '\0')
            {

                *prtD++ = *prtN++  ;
            }





        }

    }

    return 1;
}


void printTable( node *header, int len){

    node *prtH = header;
    for (int i=0; i<len; i ++)
    {

        printf(" prtH = %p | prtH->data=%s | prtH->key=%d |   prtH->next=%p, prtH->prev=%p\n", prtH, prtH->data ,prtH->key, prtH->next, prtH->prev);
        prtH=prtH->next;

    }


}



int main(int argc, const char * argv[]) {

    int lenOfTable = 15;
    node* hashHeader = initHeader(lenOfTable);

    node *newNode = (node*)malloc(sizeof(node));

    newNode->data = "KIAN";
    newNode->key = 5;
    insertHash (hashHeader, newNode);

    printTable(hashHeader, lenOfTable);

    return 0;
}
