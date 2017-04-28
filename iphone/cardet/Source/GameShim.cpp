#include "Common.h"
#include "ImageCache.h"

#include "TouchInputComponent.h"
#include "GLRendererComponent.h"

#include "GameState.h"
#include "GameTable.h"
#include "GameCard.h"

#include "SoundQueue.h"
#include "GameShim.h"


int                        gCurrTimeMs = 0;
int                        gStartTimeMs = 0;
cardet::ImageCache         gImageCache;

cardet::IRendererComponent *renderer = NULL;
cardet::IInputComponent    *input = NULL;
cardet::GameState          *gameState = NULL;
cardet::GameTable          *theTable = NULL;
cardet::GameCard           *testCard = NULL;

cardet::SoundQueue         *soundQueue = NULL;

void GameInit()
{
  gStartTimeMs = cardet::Sys_IphoneMilliseconds();
  gImageCache.Init();

  renderer = new cardet::GLRendererComponent();

  gameState = new cardet::GameState();
  input     = new cardet::TouchInputComponent();
  input->set_GameState(gameState);

  theTable = new cardet::GameTable();  
  theTable->Init();
  theTable->set_inputhandler(input);
  theTable->set_renderer(renderer);

  soundQueue = new cardet::SoundQueue();
  //kickoff the background music
  soundQueue->enqueue(SOUND_BACKGROUND_START);

  testCard = new cardet::GameCard();
  testCard->Init();
  testCard->set_inputhandler(input);
  testCard->set_renderer(renderer);
}

void GameTick()
{
  gCurrTimeMs = cardet::Sys_IphoneMilliseconds() - gStartTimeMs;

  renderer->BeginScene();

  theTable->Update();
  testCard->Update();

  renderer->EndScene();
}

void GameProcessTouch(int touchPhase, float x, float y)
{
  cardet::InputPhase phase;
  switch (touchPhase)
    {
    case TouchPhaseBegan:
      phase = cardet::Begin;
      break;
    case TouchPhaseMoved:
      phase = cardet::Move;
      break;
    case TouchPhaseEnded:
      phase = cardet::End;
      break;
    default:
      assert(false);
    }

  input->UpdateCursorPos(phase, x, y);
}

int GetSoundRequest()
{
	int sound = -1;
	soundQueue->dequeue(sound);
	return sound;
}
                  
                  




