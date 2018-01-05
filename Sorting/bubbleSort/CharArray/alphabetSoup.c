#include "stdio.h"
#include "stdbool.h"

void AlphabetSoup(char * str[]) { 
    char *head = str;
  	int len = 0;	
	char *prtlen = head;
	char *prtPrint = head;
	while (*prtlen!='\0')
	{
		prtlen++;
		len++;
	}

	
	char *prtH = head;
	 // first loop
	 for (int j=0; j <len-1; j++) {
		 // second look
		 
		for (int i=0;i<len-1;i++){
			if (prtH[i]>prtH[i+1]){
		
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

int main(void) { 

  // disable stdout buffering
  setvbuf(stdout, NULL, _IONBF, 0);
  char array[]=gets(stdin);
  // keep this function call here
  AlphabetSoup(array);
  return 0;
    
}