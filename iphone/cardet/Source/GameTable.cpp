#include "Common.h"
#include "Sprite.h"
#include "IInputComponent.h"
#include "IRendererComponent.h"
#include "GameTable.h"

namespace cardet 
{

  GameTable::GameTable() : _renderer(NULL), _inputhandler(NULL), _sprite(NULL)
  {
    
  }
  
  GameTable::~GameTable()
  {
    if(_sprite)
      delete _sprite;
    _sprite = NULL;
  }

  void GameTable::Init()
  {
    _sprite = new Sprite();
    _sprite->Init(0.0f, 0.0f, GameTableSpriteId);
  }

  void GameTable::Update()
  {
    _inputhandler->Update(this, _sprite);
    _renderer->Render(this, _sprite);
  }
  
}


