#ifndef GAMECARD_H
#define GAMECARD_H

namespace cardet
{

  class IRendererComponent;
  class IInputComponent;
  class Sprite;

  class GameCard
  {
  public:
    GameCard();
    virtual ~GameCard();

    void set_renderer(IRendererComponent *renderer) {  _renderer = renderer; }
    void set_inputhandler(IInputComponent *inputhandler) { _inputhandler = inputhandler; }
    void Init();
    void Update();

    bool get_selected() const { return _selected; }
    void set_selected(bool selected) { _selected = selected; }

  private:
    IRendererComponent *_renderer;
    IInputComponent    *_inputhandler;
    Sprite             *_sprite;
    bool                _selected;
  };

}

#endif
