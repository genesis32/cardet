#ifndef SOUNDQUEUE_H
#define SOUNDQUEUE_H

#include <queue>
#include "CardetSounds.h"

namespace cardet
{
  class SoundQueue
  {
  public:		
    SoundQueue();
    ~SoundQueue();
		
		void enqueue(const int &s);
		bool dequeue(int& s);

  private:
		std::queue<int> _sounds;
  };

}

#endif
