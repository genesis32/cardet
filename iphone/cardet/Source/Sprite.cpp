#include "Common.h"
#include "SpriteDefinitions.h"
#include "Sprite.h"

namespace cardet
{

  Sprite::Sprite()
  {
    
  }

  Sprite::~Sprite()
  {

  }

  void Sprite::Init(float x, float y, SpriteId id)
  {
    _id = id;
    _x = x;
    _y = y;
    
    _width = SpriteDefinitions[(int)id].width;
    _height = SpriteDefinitions[(int)id].height;
    _imageId = SpriteDefinitions[(int)id].imageId;
  }
	
}


