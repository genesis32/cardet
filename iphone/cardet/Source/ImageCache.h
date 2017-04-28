#ifndef IMAGECACHE_H
#define IMAGECACHE_H

#include <vector>
#include "../ThirdParty/AppleApiHelpers.h"

namespace cardet
{

  enum ImageId
  {
    GameTableImageId = 0,
    GameCardImageId  = 1,
  };

  class ImageCache
  {
  public:
    ImageCache();
    virtual ~ImageCache();

    imgdata_t const *Get(ImageId id) { return _cache[(int)id]; }
    void Clear();
    void Init();
  private:
    typedef std::vector<imgdata_t *> CacheVector;
    typedef std::vector<imgdata_t *>::iterator CacheVectorIterator;
    CacheVector _cache;
  };
}

extern cardet::ImageCache  gImageCache;

#endif

