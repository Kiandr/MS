#include "stdio.h"

int getFabenacciNumber (int n){
	int fNumber = 0;
//	int n1 = n;
//	int n2 = n;
	if (!n)
		fNumber = 0;
	else if (n==1)
		fNumber = 1;
	
	else 
	{

		// fNumber = ((n1-1)+(n2-2));
		fNumber = (getFabenacciNumber(n-1)+getFabenacciNumber(n-2));
	}

return fNumber;	

}