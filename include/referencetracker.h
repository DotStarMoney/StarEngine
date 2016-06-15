#ifndef REFERENCETRACKER_H
#define REFERENCETRACKER_H

#include <stdlib.h>
#include <unordered_map>

namespace se
{
	class ReferenceTracker
	{
	public:
		typedef int64_t key_t;

		const size_t DEFAULT_SIZE = 1024;

	private:
		std::unordered_map<key_t, size_t> keys;
		key_t counter;

	public: 
		ReferenceTracker();

		key_t acquire();
		void inc(key_t _key);
		bool dec(key_t _key);

	private:
		void clear();
	};

}


#endif