#include <iostream>

class Calculator{
	

	
	public: 
	int n;
	int p;
		
	Calculator(int n, int p){
		this->n = n;
		this->p = p;
	}
	
	int power( int a, int b){
		// resursive n power of p
		int power = a;
		// This is the special condition
		if (b ==0)
			return 1;
		// this is the end of the resurtion 
		else if (b ==1)
			return power;
		// this is the logic applied recusrively on all 
		else
			return power *this->power(power,b-1);	
//		return power;
	}

};

int main(){
	Calculator *c =  new Calculator(2,10);
	int temp = c->power (2,10);
	std::cout<<"["<<c->n <<"] power of ["<<c->p<<"] == "<<temp<<std::endl;
	
	
}