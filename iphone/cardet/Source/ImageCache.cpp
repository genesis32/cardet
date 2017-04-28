#include "Common.h"
#include "ImageCache.h"

namespace cardet
{

  const char *imageFilenames[] =
    {
      "gametable.png",
      "gamecard1.png",
      NULL
    };
  
  ImageCache::ImageCache()
  {
    
  }

  ImageCache::~ImageCache()
  {

  }

  void ImageCache::Clear()
  {
    CacheVectorIterator itr;
    for(itr = _cache.begin(); itr != _cache.end(); itr++)
      {
        imgdata_t *data = *itr;
        delete[] data->pixels;
        delete data;
      }
    _cache.clear();
  }

  void ImageCache::Init()
  {
    for(int i=0; imageFilenames[i] != NULL; i++)
      {
        imgdata_t *newData = new imgdata_t;
        Apple_ImageLoad(newData, imageFilenames[i]);
        _cache.push_back(newData);
      }
  }

}

