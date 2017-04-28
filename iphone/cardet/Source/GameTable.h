#ifndef GAMETABLE_H
#define GAMETABLE_H

namespace cardet
{

  class IRendererComponent;
  class IInputComponent;
  class Sprite;

  class GameTable
  {
  public:
    GameTable();
    virtual ~GameTable();

    void set_renderer(IRendererComponent *renderer) {  _renderer = renderer; }
    void set_inputhandler(IInputComponent *inputhandler) { _inputhandler = inputhandler; }
    void Init();
    void Update();
  private:
    IRendererComponent *_renderer;
    IInputComponent    *_inputhandler;
    Sprite             *_sprite;
  };
}

#endif
