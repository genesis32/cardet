#ifndef IINPUTCOMPONENT_H
#define IINPUTCOMPONENT_H

namespace cardet
{
  class GameTable;
  class GameCard;
  class Sprite;
  class GameState;

  enum InputPhase 
    { 
      Begin,
      Move,
      End
    };

  class IInputComponent
  {
  public:
    IInputComponent() : _gameState(NULL) { } 
    virtual ~IInputComponent() { }

    void set_GameState(GameState *gameState) { _gameState = gameState; }
    GameState *get_GameState() { return _gameState; }

    virtual void Update(GameTable *table, Sprite *sprite) = 0;
    virtual void Update(GameCard *card, Sprite *sprite) = 0;
    virtual void UpdateCursorPos(InputPhase phase, float x, float y) = 0;

  protected:
    GameState *_gameState;
  };

}

#endif

