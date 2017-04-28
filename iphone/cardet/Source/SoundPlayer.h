//
//  SoundPlayer.h
//  cardet
//
//  Created by Richard Bennett on 7/31/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CardetSounds.h"
#import "GameShim.h"
#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>


@interface SoundPlayer : NSObject {
@private
	AVAudioPlayer   *backgroundAudioPlayer;
	
	CFURLRef        applauseFileURLRef;
	SystemSoundID   applauseFileObject;	
	
	CFURLRef        tapFileURLRef;
	SystemSoundID   tapFileObject;		
}

- (void)processRequests;


@end
