#include "stdio.h"

unsigned int factorial(long int n){


    if (n >= 1)
		return n* factorial(n-1);
	else 
		 return 1;
}


int factorialFor(int n){
	

       unsigned long long factorial = 1;
	
       for(int i=1; i<=n; ++i)
        {
            factorial *= i;              // factorial = factorial*i;
        }
		
		return factorial;
	
}

int main(){
	int n ;
	scanf("%d",&n);
	//printf("%d",*n);
	for ( int i=0;i<n;i++){
	printf("factoria of %d is %u\n",i,factorial (i));
	printf("factoria of %d is %u\n",i,factorialFor (i));
}
	return 0;
}