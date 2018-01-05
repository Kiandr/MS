#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void calculateTotal (float *head, int len){
	
	float total = 0;
	
	total = head[0] +(head[0]*head[1]/100)+(head[0]*head[2]/100);
    int totalRounded = round(total);
	printf ("The total meal cost is %d dollars.",totalRounded);
	
	
	
	
}


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int x = 3;

	float array [3];
	float len = sizeof(array)/sizeof(float);

	for (int i =0;i<len;i++)
	{
		scanf("%f", &array[i]);
		x--;
	}
	
	 calculateTotal (array, len);
  
  
    return 0;
}




// 10.25
// 17
// 5
// expected 13