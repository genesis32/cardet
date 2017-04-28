#include <sys/time.h>
#include "Common.h"
#include "Util.h"

namespace cardet
{

  const char *GetSystemPathForFile(const char *filename)
  {
    return filename;
  }
  
  int Sys_IphoneMilliseconds() {
    struct timeval tp;
    struct timezone tzp;
    static int secbase = 0;
    
    gettimeofday( &tp, &tzp );
    
    if(secbase == 0) 
    {
      secbase = tp.tv_sec;
      return (tp.tv_usec / 1000);
    }
    
    int curtime = (tp.tv_sec - secbase) * 1000 + (tp.tv_usec / 1000);
	
    return curtime;
  }

  float TransformXToWorld(float xPixel)
  {
    return -1.0f + (xPixel / (SCREEN_WIDTH / 2.0f));
  }

  float TranslateXToWorld(float xPixelFrom, float xPixelTo)
  {
    return TransformXToWorld(xPixelTo) - TransformXToWorld(xPixelFrom);
  }

  float TransformYToWorld(float yPixel)
  {
    return -1.0f + (yPixel / (SCREEN_HEIGHT / 2.0f));
  }

  float TranslateYToWorld(float yPixelFrom, float yPixelTo)
  {
    return TransformYToWorld(yPixelTo) - TransformYToWorld(yPixelFrom);
  }
  
}
