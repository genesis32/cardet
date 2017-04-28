#ifndef UTIL_H
#define UTIL_H

namespace cardet
{
  // HIGH RES THIS NEEDS TO CHANGE... PROBABLY GLOBAL VARIABLE SOMEWHERE
  const float SCREEN_WIDTH = 320;
  const float SCREEN_HEIGHT = 480;

  int Sys_IphoneMilliseconds();
  const char *GetSystemPathForFile(const char *filename);

  float TransformXToWorld(float xPixel);
  float TransformYToWorld(float yPixel);
  float TranslateXToWorld(float xPixelFrom, float xPixelTo);
  float TranslateYToWorld(float yPixelFrom, float yPixelTo);
}

#endif

