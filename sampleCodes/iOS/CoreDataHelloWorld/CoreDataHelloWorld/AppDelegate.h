//
//  AppDelegate.h
//  CoreDataHelloWorld
//
//  Created by Kian Davoudi-Rad on 2017-08-21.
//  Copyright © 2017 Kian Davoudi-Rad. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong) NSPersistentContainer *persistentContainer;

- (void)saveContext;


@end

