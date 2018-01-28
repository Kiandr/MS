#include "stdio.h"
#include "stdbool.h"

void sort(char *head){
	
	int len = 0;	
	char *prtlen = head;
	char *prtPrint = head;
	while (*prtlen!='\0')
	{
		prtlen++;
		len++;
	}

	bool go = false;
	char *prtH = head;
	 // first loop
	 for (int j=0; j <len-1; j++) {
		 // second look
		 go = false;
		for (int i=0;i<len-1;i++){
			if (prtH[i]>prtH[i+1]){
			go = true; 
			char temp = prtH[i];
			prtH[i] = prtH[i+1];
			prtH[i+1] = temp;
			}	
		}
//	if (go == false)
	//	break;
	}
	
	
	for(int k=0; k<len; k++)
		printf("%c", *(prtPrint+k));
	printf("\n");
	
}


int main(){

	char array [] = {"HGFEDCBA"};
	int len = sizeof(array)/sizeof(char);
	
	
	
	//for(int i=0; i<len; i++)
		//printf("i = %d  [i]=%c\n", i,array[i]);


	sort(array);
	

	//for(int i=0; i<len; i++)
		//printf("i = %d  [i]=%c\n", i, array[i]);
	
	
	return 0;
}


/*void AlphabetSoup(char * str[]) { 
  
  // code goes here  
  printf("%s", str); 
            
}

int main(void) { 

  // disable stdout buffering
  setvbuf(stdout, NULL, _IONBF, 0);
  
  // keep this function call here
  AlphabetSoup(gets(stdin));
  return 0;
    
} 

*/



