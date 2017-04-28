#ifndef GAMESHIM_H
#define GAMESHIM_H

#include "CardetSounds.h"

#define TouchPhaseBegan 0
#define TouchPhaseMoved 1
#define TouchPhaseEnded 2

#ifdef __cplusplus
extern "C"
{
#endif

  void GameInit();
  void GameProcessTouch(int touchPhase, float x, float y);
  void GameTick();
  int  GetSoundRequest();

#ifdef __cplusplus
}
#endif

#endif
