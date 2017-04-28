#ifndef SPRITE_H
#define SPRITE_H

#include "ImageCache.h"
#include "SpriteDefinitions.h"

namespace cardet
{

  class Sprite
  {
  public:
    Sprite();
    virtual ~Sprite();

    void set_x(float x) { _x = x; }
    void set_y(float y) { _y = y; }
    void set_width(float width) { _width = width; }
    void set_height(float height) { _height = height; }

    float get_x() const { return _x; }
    float get_y() const { return _y; }
    float get_width() const { return _width; }
    float get_height() const { return _height; }

    ImageId get_imageId() const { return _imageId; }

    void Init(float, float, SpriteId);
    
  private:
    ImageId  _imageId;
    SpriteId _id;
    float _x;
    float _y;
    float _width;
    float _height;
  };

}

#endif
