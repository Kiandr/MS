// writing Encapsulation in Objective C


#import<Foundation/Foundation.h>

/*
Theory: All objective programs are consisted of two fundamental structures.

1- Program statement (code), this is a part of the program that calls methods and performs actions.
2- Program data: the data is the information of thepogram which affected by theprogram function. 

Encapsulation is an objected Oriented Programming concept that binds toghether the data and functiont hat manipulates the data and that keeps both safe from outside interfecence and mussue. The data encapsulation led to theimport ot OOP conepct of data binding. 
- Data encapsulation is the mechanisim of bunding data and function to use them
- Data Abstraction is the mechanisim of only exposing interfaces and hiding the implementation.  

*/


@interface Adder:NSObject
// local vars
{ 
NSInteger total;
}

// properties
// Data Abstraction Exposes certain functions
// Public Methods 
-(id) initWithInitalNumber:(NSinteger) initalNumber;
-(void) addNumber:(NSinteger) newNumber;
-(NSInteger) getTotal;
@end

@Implementation Adder
// Data Encapsulation: the value of local Var total has never been exposed, nor the var itself. 
-(id) initWithInitalNumber:(NSinteger) initalNumber{
total = initalNumber;
return self;
}
// This is dataAbstarction, because there is a function that enables access to the local var.
-(void) addNumber:(NSinteger) newNumber{
total = total + newNumber;
}


// Data Encapsulation, becuase there is encapsulated function which wrappes the local val, and provides access to thel class memebers
-(NSInteger) getTotal{
return total;
}

@end



int main(int argc, const char * argv[]){
NSAutoreleasePool *pool = [[NSAutoreleasePool alloc]init];
Adder *adder = [[Adder alloc]initWithInitalNumber:10];
[adder addNumber:10];
[adder getTotal];

}