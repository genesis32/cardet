//
//  cardetAppDelegate.h
//  cardet
//
//  Created by David Massey on 7/24/10.
//  Copyright N/A 2010. All rights reserved.
//

#import <UIKit/UIKit.h>

@class EAGLView;

@interface cardetAppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    EAGLView *glView;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet EAGLView *glView;

@end

