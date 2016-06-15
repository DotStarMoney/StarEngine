#include "referencetracker.h"

namespace se
{
	ReferenceTracker::ReferenceTracker()
	{
		clear();
	}

	ReferenceTracker::key_t ReferenceTracker::acquire()
	{
		// WARNING: DEBUG ERROR MISUSE if no space remains'
		key_t new_key = counter++;
		keys[new_key] = 1;
		return new_key;
	}
	void ReferenceTracker::inc(ReferenceTracker::key_t _key)
	{
		// WARNING: DEBUG ERROR MISUSE if key is not being tracked
		keys[_key]++;
	}
	bool ReferenceTracker::dec(ReferenceTracker::key_t _key)
	{
		// WARNING: DEBUG ERROR MISUSE if key is not being tracked
		if (keys[_key]-- == 0)
		{
			keys.erase(_key);
			return true;
		}
		return false;
	}
	void ReferenceTracker::clear()
	{
		keys.clear();
		keys.reserve(DEFAULT_SIZE);
		counter = 0;
	}

}