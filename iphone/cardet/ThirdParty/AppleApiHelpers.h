#ifndef APPLEIMAGELOADER_H
#define APPLEIMAGELOADER_H

#include <stdint.h>

namespace cardet
{

  typedef struct imgdata_s
  {
    int     width;
    int     height;
    int     bpp;
    int     hasAlpha;
    uint8_t *pixels;
  } imgdata_t;

  void Apple_ImageLoad(imgdata_t *out, const char *path);

}

#endif

