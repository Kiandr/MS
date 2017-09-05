#import<Foundation/Foundation.h>
/* Imagine that you can change the type of the objectst that inheritance from; 
Protocols are refference to interfaces, that your class has access to. 
This inherited class, shall contain implementations of protocols. its pretty much like polymorphosim, with some more sophisticated rules. 
In Protocols, you should implemente any required method. In protocols, you can have implementations of the protocol methos polymorphosized. 
Which means, you can have multiple implementations of the same protocol I guess. 
*/

/*
What is id: "id" is technically a var
id is a pointer to any type, but unlike void * it always points to an Objective-C object. For example, 
you can add anything of type id to an NSArray, but those objects must respond to retain and release.

*/

@protocol PrintProtocolDelegate
// in iOS 10 above
@required
-(void) processCompleted;
@end 

@interface PrintClass:NSObject
// LocalVariable 
{
id delegate;
}

-(void) printDetails;
-(void) setDelegate: (id) newDelegate
@end

@implementations printClass
-(void) printDetails{
NSLog(@"Print Detail method");

}

-(void) setDelegate: (id) newDelegate{
delegate = newDelegate;

}

@end


/* Dont have to implement or reffee to the protocol required memeber in interface, but implementation*/
@interface sampleClass:NSobject <PrintProtocolDelegate>
-(void) startAction;

@end

@implementation SampleClass{
// this is the interface requied method
-(void) startAction{
PrintClass *printClass [[PrintCloass alloc]init];
[printClass setDelegate:self];
[printClass printDetails];

}
// This is the protocol implementation
-(void) processCompleted{
NSLog(@"Print Process Completed");
}

}

int main(int argc, const char * argv[]){
NSAutoreleasePool *pool = [[NSAutoreleasePool alloc]init];

SampleClass *sampleClass = [[SampleClass alloc]init];
[sampleClass startAction];


return 0;
}

