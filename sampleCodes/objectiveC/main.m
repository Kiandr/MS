#import<Foundation/Foundation.h>

@interface Box:NSObject
// private instanct, no access to other classes
{ 
double length; 
double breadth; 
}

// this is a property, properties are used  to provide access to class instance variables in other classes
@property (nonatomic, readwrite) double height; 

-(double) volume;

@end

@implementation Box
// synghesize tells compiler to build getter/setter
@synghesize height; 

// this is custroctore
-(id) init 
{
	self = [super init];
	// from here you can define your functions
	length = 10;
	breadth = 20;
	
	return self;
}
// function implementation
-(double) volume
{
	return length*breadth;
}
@end


