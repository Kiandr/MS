#include <stdio.h> 

void CheckNums(int num1[], int num2[]) {
	char True[] = {"true"};	
	char False[] = { "false" };
	if (num1 < num2)
		printf("%s", True);
	else if (num1 == num2)
		printf("%d", -1);
	else if (num1 > num2)
		// code goes here  
		printf("%d", False);

}

int main(void) {

	// disable stdout buffering
	setvbuf(stdout, NULL, _IONBF, 0);

	// keep this function call here
	CheckNums(1,8);
	return 0;

}

