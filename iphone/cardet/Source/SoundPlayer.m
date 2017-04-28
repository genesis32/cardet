//
//  SoundPlayer.m
//  cardet
//
//  Created by Richard Bennett on 7/31/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "SoundPlayer.h"



@implementation SoundPlayer

- (id)init
{
	if ((self = [super init]))
	{
		NSError *error;
		
		//create background music that loops
		NSURL *backgroundSound = [[NSBundle mainBundle] URLForResource: @"background" withExtension: @"aif"];
		backgroundAudioPlayer = [[AVAudioPlayer alloc] initWithContentsOfURL:backgroundSound error:&error];
		backgroundAudioPlayer.numberOfLoops = -1;
		
		//create applause
		NSURL *applauseSound   = [[NSBundle mainBundle] URLForResource: @"applause" withExtension: @"aif"];
		applauseFileURLRef = (CFURLRef) [applauseSound retain];
		AudioServicesCreateSystemSoundID (applauseFileURLRef, &applauseFileObject);
		
		//create tap
		NSURL *tapSound   = [[NSBundle mainBundle] URLForResource: @"tap" withExtension: @"aif"];
		tapFileURLRef = (CFURLRef) [tapSound retain];
		AudioServicesCreateSystemSoundID (tapFileURLRef, &tapFileObject);		
	}
	
	return self;
}

-(void) processRequests
{
	int req;
	
	while ((req = GetSoundRequest()) >= 0)
	{
		switch (req)
		{
			case SOUND_BACKGROUND_START:
				[backgroundAudioPlayer play];
				break;
			case SOUND_BACKGROUND_STOP:
				[backgroundAudioPlayer stop];
				break;
			case SOUND_VIBRATE:
				AudioServicesPlaySystemSound (kSystemSoundID_Vibrate);
				break;
			case SOUND_APPLAUSE:
				AudioServicesPlaySystemSound (applauseFileObject);
				break;
			case SOUND_TAP:
				AudioServicesPlaySystemSound (tapFileObject);
				break;
		}
		printf("got sound request %d", req);
	}
	
}

- (void)dealloc
{
	AudioServicesDisposeSystemSoundID (applauseFileObject);
	CFRelease (applauseFileURLRef);

	AudioServicesDisposeSystemSoundID (tapFileObject);
	CFRelease (tapFileURLRef);
	
	[super dealloc];
}

@end
