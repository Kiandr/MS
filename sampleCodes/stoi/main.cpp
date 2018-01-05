// A C++ program for implementation of atoi
#include <stdio.h>
#include <string.h>
// A simple atoi() function
int myAtoi(char *str)
{
    int res = 0;  // Initialize result
    int sign = 1;  // Initialize sign as positive
    int i = 0;  // Initialize index of first digit
      
    // If number is negative, then update sign
    if (str[0] == '-')
    {
        sign = -1;  
        i++;  // Also update index of first digit
    }
      
    // Iterate through all digits and update the result
    for (; str[i] != '\0'; ++i)
        res = res*10 + str[i] - '0';
    
    // Return result with sign
    return sign*res;
}

int kAtoi(char *str){
	int result = 0;
	char letter[strlen(str)];
	int negative = 1;
	strcpy(letter, str);
	printf("string is %s  len is %lu\n",letter, strlen (str));
	
	if (*letter == '-'){
		negative = -1;
	char *prtH = str+1;
	int sizeL = strlen(str)-1;
	int x;
//	sscanf(*prtH, "%d", &x);
	x = *prtH;
 	printf("\nThe value of x : %d\n", x);
	}
	else {
	negative = 1;
	char *prtH = str;
	int sizeL = strlen(str);
	int x;
	sscanf(prtH, "%d", &x);
 	printf("\nThe value of x : %d\n", x);
    
		
		
	}
	
	
	
	return result;
}
  
// Driver program to test above function
int main()
{
    char str[] = "-123";
    int val = myAtoi(str);
    printf ("%d\n", val);
	kAtoi(str);
    return 0;
}