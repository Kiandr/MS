#include "stdio.h"

void bubbleSortIntArray( int *head, int len){

for (int j=0;j<len-1;j++){
	for (int i=0;i<len-1;i++){
		{
			if (head[i]>head[i+1])
			{
				int temp = head[i];
				head[i] = head[i+1];
				head[i+1] = temp;
				
			}
		}
		printf("%d = %d\n", i, head[i]);
	}
  }

}

int main(){



int arr[]={5,3,7,9,1,4,2,8,6};
printf("BeforeTest\n");
for (int i=0; i< sizeof(arr)/sizeof(int);i++){
printf("i= %d i[%d]=%d \n", i,i,arr[i]);

}


bubbleSortIntArray (arr,(sizeof(arr)/sizeof(int)));
printf("AfterTest\n");
for (int i=0; i< sizeof(arr)/sizeof(int);i++){
printf("i= %d i[%d]=%d \n", i,i,arr[i]);

}




return 0;

}