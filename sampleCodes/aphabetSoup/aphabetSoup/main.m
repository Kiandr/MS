#include <stdio.h>
#include "stdbool.h"

void AlphabetSoup(char * str) {
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

int main(void) {
    char inpout [] = "coderbyte";
    AlphabetSoup(inpout);


    
    return 0;
}
