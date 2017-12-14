#include <iostream>
#include <string>

int solution (char *s){
	int max =0;
	for (int i;i<strlen(s);i++){
		char temp[strlen(s+i)];
		strcpy(temp, s+i);
//		printf("%s\n", s+i);
		printf("%s\n", temp);
//		printf("len=%lu\n",strlen(temp));
		if (strlen(s+i)>max)
			max = strlen(s+i);
	}
	
	
	return max;
}


int main(){
	char testOne []= "codity";
	printf("%d\n",solution (testOne));
}