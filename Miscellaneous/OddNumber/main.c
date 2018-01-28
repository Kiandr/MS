#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void isOdd (int n ){
    
    
       if (n%2 == 0)
          printf("Not Weird\n");
        else 
          printf("Weird\n");
    
}


int main(){
   // int N; 
   // scanf("%d",&N);
	for (int i=0;i<50;i++){
		printf("i=%d",i);
    isOdd(i);
}
    return 0;
}