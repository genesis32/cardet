#include "Common.h"
#include "Sprite.h"
#include "GameCard.h"
#include "GameState.h"
#include "TouchInputComponent.h"

namespace cardet
{

  TouchInputComponent::TouchInputComponent()
  {
    _currFingerPos.x = -1.0f;
    _currFingerPos.y = -1.0f;
  }

  TouchInputComponent::~TouchInputComponent()
  {

  }

  bool TouchInputComponent::IsTouching(Sprite *sprite)
  {
    if(_currFingerPos.x >= sprite->get_x() &&
       _currFingerPos.x <= (sprite->get_x() + sprite->get_width()) &&
       _currFingerPos.y >= sprite->get_y() &&
       _currFingerPos.y <= (sprite->get_y() + sprite->get_height()))
      {
        return true;
      }
    return false;
  }

  void TouchInputComponent::Update(GameTable *table, Sprite *sprite)
  {

  }
  
  void TouchInputComponent::Update(GameCard *card, Sprite *sprite)
  {
    if(_currFingerPos.phase == Begin)
      {
        bool isTouched = IsTouching(sprite);
        card->set_selected(isTouched);
      }
    else if(_currFingerPos.phase == Move) 
      {
        if(card->get_selected())
          {
            sprite->set_x(_currFingerPos.x - sprite->get_width() / 2.0f);
            sprite->set_y(_currFingerPos.y - sprite->get_height() / 2.0f);
          }
      }
    else if(_currFingerPos.phase == End)
      {
        if (card->get_selected())
          {
            _gameState->PlayCard(card);
            card->set_selected(false);
          }
      }
  }

  void TouchInputComponent::UpdateCursorPos(InputPhase phase, float x, float y)
  {
    _currFingerPos.phase = phase;
    _currFingerPos.x = x;
    _currFingerPos.y = SCREEN_HEIGHT - y; // 0,0 is actually 0,460 on the iphone screen.
  }

}

