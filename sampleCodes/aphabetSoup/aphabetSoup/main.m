#include <stdio.h>
#include "stdbool.h"

void AlphabetSoup(char * str[]) {

    // find Lend of Char
    int l =0;
    char *prtLen = str;

    while (*prtLen != '\0')
    {
        l++;
        prtLen++;
    }

    for (int j =0; j<l; j++){

        // setTwoPointers n and n+1
        char *prtN = str;
        char* prtNext = prtN+1;
        char *prtEndOfCharArray = prtN + l;

        for (int i =0; i<l; i++){
            // repeat this process for all memeber of the array
            while (prtNext<prtEndOfCharArray)
            {
                if (*prtN>*prtNext)
                {
                    char temp = *prtN;
                    *prtN = *prtNext;
                    *prtNext = temp;
                }
                // printf("%s\n",str);
                prtN++;
                prtNext++;
            }

        }
    }

    printf("%s", str);

}

void bubbleSortIntegerArray(int *head, int len)
{
    int *prtHead = head;
    for (int k=0; k<len; k++){
        printf("Element %d = %d\n",k,*(prtHead+k));
    }
    int const *prtToHeader = head;
    int *prtH = head;
    int *prtNext  = prtH+1;
    //for (int i = 0; i<len;i++)
    {
      //  while (prtNext!=NULL)
        for (int j=1; j<len;j++){
            if (*prtH > *prtNext)
            {

                int temp = *prtH;
                *prtH    = *prtNext;
                *prtNext = temp;

            }
            printf("j= %d, prtH:%d prtNext:%d\n", j,*prtH,*prtNext);
            prtH++;
             prtNext++;

        }
      //  prtH = head+i;
       // prtNext  = head+i+1;

    }


}

int main(void) {
    char inpout [] = "coderbyte";
    //int inputArray[] = {5,4,3,2,1};
    int inputArray[] = {1,3,2,4,5,6};
  //  AlphabetSoup(inpout);
    int len = sizeof(inputArray)/sizeof(int);
    bubbleSortIntegerArray(inputArray,len);


    
    return 0;
}
