#ifndef GLGAMETABLERENDERCOMPONENT_H
#define GLGAMETABLERENDERCOMPONENT_H

#include <map>
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include "IRendererComponent.h"

namespace cardet
{

  class GameTable;
  class GameCard;
  class Sprite;

  class GLRendererComponent : public IRendererComponent
  {
  public:
    GLRendererComponent();
    virtual ~GLRendererComponent();

    virtual void BeginScene();
    virtual void EndScene();

    virtual void Render(GameTable *, Sprite *);
    virtual void Render(GameCard *, Sprite *);

    virtual void Shutdown();

  private:
    GLuint LoadTexture(ImageId imageId);
    typedef std::map<ImageId, GLuint> ImageIdToGLTexMap;
    typedef std::map<ImageId, GLuint>::iterator ImageIdToGLTexMapIterator;
    
    ImageIdToGLTexMap _imageIdToGLMap;
  };

}

#endif


