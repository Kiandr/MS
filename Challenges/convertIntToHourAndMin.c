#include "stdio.h"


void TimeConvert(int num[]) {



// code goes here
printf("%d", num);

}

int main(void) {

// disable stdout buffering
setvbuf(stdout, NULL, _IONBF, 0);

// keep this function call here
TimeConvert(gets(stdin));
return 0;

}