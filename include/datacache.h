#ifndef DATACACHE_H
#define DATACACHE_H
#include <string>
#include <list>
#include <unordered_map>
#include <stdlib.h>

namespace se
{
	class DataCache
	{
	public:
		const size_t DEFAULT_MAX_RAW_BYTES = 536870912; //512MiB
		const size_t DEFAULT_MAX_ITEM_BYTES = 16777216; //16MiB
	private:
		class frame
		{
		public:
			frame() { data = nullptr; }
			~frame() { if (data) free(data);  }
			std::string key;
			void* data;
			size_t size;
		};

		size_t total_bytes;
		size_t maximum_bytes;
		size_t maximum_item_bytes;
		std::unordered_map<std::string, std::list<frame>::iterator> data_table;
		std::list<frame> priority_list;
	public:
		DataCache();
		DataCache(size_t _max_raw_bytes, size_t _max_item_bytes);
		void set_max_raw_bytes(size_t _bytes);
		void set_max_item_bytes(size_t _bytes);
		bool retrieve(const std::string& _key, size_t& _bytes, void*& _data);
		bool insert(const std::string& _key, size_t _bytes, void* _data);
	private:
		void adjust();
	};
}

#endif