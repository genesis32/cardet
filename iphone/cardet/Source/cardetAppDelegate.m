//
//  cardetAppDelegate.m
//  cardet
//
//  Created by David Massey on 7/24/10.
//  Copyright N/A 2010. All rights reserved.
//

#import "cardetAppDelegate.h"
#import "EAGLView.h"
#import "GameShim.h"

@implementation cardetAppDelegate

@synthesize window;
@synthesize glView;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [glView startAnimation];
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    [glView stopAnimation];
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
  GameInit();
  [glView startAnimation];
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    [glView stopAnimation];
}

- (void)dealloc
{
    [window release];
    [glView release];

    [super dealloc];
}

@end
