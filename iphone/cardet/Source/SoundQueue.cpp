#include "SoundQueue.h"

namespace cardet
{

  SoundQueue::SoundQueue()
  {
    
  }
  
  SoundQueue::~SoundQueue()
  {
  }
	
	void SoundQueue::enqueue(const int &s)
	{
		_sounds.push(s);
	}
	
	bool SoundQueue::dequeue(int &s)
	{
		if (_sounds.size() >= 1)
		{
			s = _sounds.front();
			_sounds.pop();
			return true;
		}
		
		return false;
	}
}
