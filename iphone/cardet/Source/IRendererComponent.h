#ifndef RENDERERCOMPONENTS_H
#define RENDERERCOMPONENTS_H

namespace cardet
{

  // Interfaces for all the rendering components
  class GameTable;
  class GameCard;
  class Sprite;

  class IRendererComponent
  {
  public:
    IRendererComponent() { };
    virtual ~IRendererComponent() { };

    virtual void BeginScene() = 0;
    virtual void EndScene() = 0;

    virtual void Render(GameTable *, Sprite *) = 0;
    virtual void Render(GameCard *, Sprite *)  = 0;

    virtual void Shutdown() = 0;
  };

}

#endif

