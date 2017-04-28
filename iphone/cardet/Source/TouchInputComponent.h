#ifndef TOUCHINPUTCOMPONENT_H
#define TOUCHINPUTCOMPONENT_H

#include <vector>
#include "IInputComponent.h"

namespace cardet
{

  typedef struct cursorinput_s
  {
    InputPhase phase;
    float x;
    float y;
  } cursorinput_t;

  class GameTable;
  class GameCard;
  class Sprite;
  class GameState;

  class TouchInputComponent : public IInputComponent
  {
  public:
    TouchInputComponent();
    virtual ~TouchInputComponent();

    virtual void Update(GameTable *table, Sprite *sprite);
    virtual void Update(GameCard  *card, Sprite *sprite);
    void UpdateCursorPos(InputPhase phase, float x, float y);
  private:
    bool IsTouching(Sprite *sprite);
    volatile cursorinput_t _currFingerPos;
  };

}

#endif


