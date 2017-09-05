#import<Foundation/Foundation.h>
/* Imagine you have already a class that has been used in distribution and ihnerited by many. 
Now, if you have the source code, you can go and eddit the code by adding new classes, or you can use the extensions in Objective c. 
Whuile thereis not much difference between adding a new method in the interface and then the implementation class, vs extensions, 
there is an issue, when you dont have access to the source code of that class. In those cases, you can use Categories. Categories, 
capacity to extend existing class without need for the source code. 
Here are some examples. 
*/

/*What is the difference between - and +
A - is an instance of a class, that you have to initalize to use it. 
A + is an instance of a method, that you can have access to without initaliziation. 
*/

// This is a Category, where I dont have source code
@interface NSString (myAdditionalCategory)
+(NSString) getCopyRightString;

@end

@implementation NSString (myAdditionalCategory)

+(NSString) getCopyRightString{
return @"Copyright KianDavoudiRad 2017";

}
@end

int main(int argc, const char *arhv[]){


NSAutorealeasePool *pool = [[NSAutorealeasePool alloc]init];

NSString *copyRightVar = [NSString getCopyRightString];
NSLog(copyRightVar);

return 0;
}