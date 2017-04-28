#ifndef GAMESTATE_H
#define GAMESTATE_H

namespace cardet
{
  class GameCard;
   
  class GameState
  {
  public:
    GameState();
    ~GameState();
    
    void PlayCard(const GameCard *card) const;
    
  };
  
}

#endif

