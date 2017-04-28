#import "AppleApiHelpers.h"

namespace cardet
{

  void Apple_ImageLoad(imgdata_t *out, const char *filename)
  {

    NSString *nsFilePath = [[NSString alloc] initWithUTF8String: filename];
    NSString *path       = [[NSBundle mainBundle] pathForResource:nsFilePath ofType: nil];

    NSData   *texData    = [[NSData alloc]    initWithContentsOfFile:path];
    UIImage  *image      = [[UIImage alloc]   initWithData:texData];

    if (image == nil)
      NSLog(@"Do real error checking here");
  
    int width = CGImageGetWidth(image.CGImage);
    int height = CGImageGetHeight(image.CGImage);
    uint8_t *imageData = new uint8_t[height * width * 4];

    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
    CGContextRef    context = CGBitmapContextCreate( imageData, width, height, 8, 4 * width, colorSpace, kCGImageAlphaPremultipliedLast | kCGBitmapByteOrder32Big );
    CGColorSpaceRelease( colorSpace );
    CGContextClearRect( context, CGRectMake( 0, 0, width, height ) );
    CGContextTranslateCTM( context, 0, height - height );
    CGContextDrawImage( context, CGRectMake( 0, 0, width, height ), image.CGImage );

    out->width    = width;
    out->height   = height;
    out->bpp      = 4;
    out->hasAlpha = true;
    out->pixels   = imageData;

    // glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

    CGContextRelease(context);

    [nsFilePath release];
    [image release];
    [texData release];
  }

}

