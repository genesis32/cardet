#include "Common.h"
#include "Sprite.h"
#include "IInputComponent.h"
#include "IRendererComponent.h"
#include "GameCard.h"

namespace cardet
{

  GameCard::GameCard() : _sprite(NULL), _selected(false)
  {
    
  }
  
  GameCard::~GameCard()
  {
    if(_sprite)
      delete _sprite;
    _sprite = NULL;
  }
  
  void GameCard::Init()
  {
    _sprite = new Sprite();
    _sprite->Init(0.0f, 0.0f, GameCardSpriteId);
  }
  
  void GameCard::Update()
  {
    _inputhandler->Update(this, _sprite);
    _renderer->Render(this, _sprite);
  }

}
