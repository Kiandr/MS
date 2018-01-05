#include<queue>
#include<iostream>

int main(){
	
	std::queue<int> test; 
	
	test.push(0);
	test.push(1);
	test.push(2);
	test.push(3);
	
	while (!test.empty()){
		printf("%d\n", test.front());
	//printf("%d\n", test.back());
	test.pop();
	test.push(0);
	printf("%d\n", test.front());
}
	
	return 0;
}