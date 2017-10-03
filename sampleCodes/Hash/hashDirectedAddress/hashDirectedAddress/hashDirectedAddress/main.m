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
 Auhtor: Kian D.Rad
 Date: Oct 3rd 2017
 ReadMe: Basic data sctructur for a has function. There is a hash index and hash data.
 */
typedef struct node{

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
    return key * 10;
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
    node* htoPrt = prtH;
    int n = len;
    int i =1;
    node* prtPrev = NULL;

//    prtH = (node*) malloc(sizeof(node*));
//    prtH->key =0;
//    prtH->prev = NULL;
//    prtH->next = NULL;

    while (n){
//        prtH = (node*) malloc(sizeof(node*));
        prtH->key = i;
        //*prtH->data = '\0';
        prtH->prev = prtPrev;
        prtH->next =  (node*) malloc(sizeof(node*));;
        prtH->next->prev = prtH;
        // Keep track of the prev pointer.
         printf(" prtH = %p | prtH->key=%d |   prtH->next=%p, prtH->prev=%p\n", prtH, prtH->key, prtH->next, prtH->prev);
        prtPrev = prtH;
        prtH=prtH->next;
        i++;
        n--;
    }

    return header;
}





bool insertHash (node *header, node *aNode){

    if (!header)
        return 0;
    else {
        /*
         this method will tell you how many nodes do you have to move forward.
         */
        int index = hashCode(aNode->key);



    }






    return 1;
}






int main(int argc, const char * argv[]) {
    node* hashHeader = initHeader(3);



    return 0;
}
