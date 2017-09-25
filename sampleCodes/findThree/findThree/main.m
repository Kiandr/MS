#include "stdio.h"

int find( int arr[]){
    printf("%d",sizeof(arr)/sizeof(int));
    int* prtl = arr;
    int len = 0;
    while (prtl>NULL){ prtl++;len++;}

    int *prtH =  arr;
    int *prtX0=  arr+1;
    int *prtX1 = arr+2 ;
    int *prtX2 = arr+(len-1);



    for (int i=1; i<len;i++){
        while (prtX1<prtX2){

            if ((*prtX0+*prtX1+*prtX2)==*arr)
                return 1;
            else {

                prtX2++;

            }

        }



    }

    return 0;


}


int main()
{

    int arr [] ={10,2,2,6};
    printf("%d",find(arr));
    return 0;
}
