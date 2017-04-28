#ifndef SPRITEDEFINITIONS_H
#define SPRITEDEFINITIONS_H

#include "ImageCache.h"

namespace cardet
{

  enum SpriteId
    {
      GameTableSpriteId = 0,
      GameCardSpriteId  = 1
    };

  typedef struct spritedef_s
  {
    float   width;
    float   height;
    ImageId imageId;
  } spritedef_t;
  
  extern spritedef_t SpriteDefinitions[];
}

#endif

