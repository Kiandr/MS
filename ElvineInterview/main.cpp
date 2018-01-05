/*
Kian D.Rad
Preparing for interviews January 4th 2017:
*/

#include "stdio.h"


int fooFabenachi(int a){

int f=0;

if (a==0)
	return 0;
else if (a==1)
	return 1 ;
else {
	f=fooFabenachi(a-1)+fooFabenachi(a-2);
}
return f;

}


int fooFactorial(int a){
	
	if (a>1)
		return (a*fooFactorial(a-1));
	else if (a==1)
		return 1;

		return 0;
	
}

int main(){

	printf("Fabenacci result is %d\n",fooFabenachi(10));
	printf("Factorial result is %d\n",fooFactorial(4));

}