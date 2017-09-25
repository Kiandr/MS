#include "stdio.h"


typedef struct node{
    char *prtStart;
    char *prtEnd;
    int l;

}node;

void LongestWord(char * sen[]) {
node arrayNodes [10];
    node *prtToLongest = arrayNodes;
    int prtLenTotal = 0;
    char *prtL = sen;
    int spacesNum = 0;
    while(*prtL!='\0'){
        if (*prtL == ' ')
            spacesNum=spacesNum+1;
        prtL++;
}

char *prt = sen;
char *prtStart = NULL;
char *prtEnd = NULL;
int globalLen = 0;
//node arrayNodes [spacesNum+1];

    node* prtToNodes = arrayNodes;



    //for (int i =0 ; i<spacesNum ; i++){
    while (prt!='\0'){
if (( *prt>='A' && *prt<='Z')|| ( *prt>='a' && *prt<='z') && (*prt!='\0'))
{


    {
    prtStart = prt;
    while (*prt!= ' ' &&*prt!= '\0' && prt){
 prtEnd = prt;
        prt++;
    }
        if (*prtEnd!= '\0'){
    //prtEnd = prt;
    globalLen = prtEnd-prtStart;
    prtToNodes->prtStart = (char*)prtStart;
    prtToNodes->prtEnd = (char*)prtEnd;
    prtToNodes->l = globalLen;
    prtToNodes++;
    prtStart = prtEnd++;
    prtEnd = NULL;
    printf("%d\n", globalLen);
        prt++;
    }


    }
}
   
//else prt++;
    }
// code goes here
int t=0;
    node *tempPrt  = NULL;
    for (int k=0;k<10;k++){

        if (t<arrayNodes[k].l){
            t=arrayNodes[k].l;
            tempPrt = (node*)arrayNodes+k;
        }

        printf("%s AND %d", tempPrt->prtStart,tempPrt->l);



    }




printf("%s", sen);

}

int main(){

    char Arr[]= "KIAN DAVOUDI RAD IS HERE";
    LongestWord(Arr);

}

