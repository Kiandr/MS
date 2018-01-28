#include "stdio.h"


typedef struct node{
    char *prtStart;
    char *prtEnd;
    int l;

}node;

void LongestWord(char * sen[]) {
	char *prtL = sen;
	int spacesNum =0;
	while(prtL!='\0'){
		if (*prtL == ' ')
			spaceNum++;
		prtL++;}
	}
	
    char *prt = sen;
    char *prtStart = NULL;
    char *prtEnd = NULL;
    int globalLen = 0;
    node arrayNodes [] = (node*)malloc(sizeof(node));
	
	


    if (( *prt>='A' && *prt<='Z')|| ( *prt>='a' && *prt<='z') && (*prt!='\0'))
    {
        prtStart = prt;
        while (*prt!= ' ')
            prt++;
        prtEnd = prt;
        globalLen = prtEnd-prtStart;
        printf("%d", globalLen);

    }

    else prt++;

    // code goes here
    printf("%s", sen);

}

int main(){

    char Arr[]= "KIAN DAVOUDI RAD";
    LongestWord(Arr);

}

