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
-(void) processCompleted;0
@end 

@interface PrintClass:NSObject
// LocalVariable 
{
id delegate;
}

-(void) printDetails;
-(void) setDelegate: (id) newDelegate
@end