#include "datacache.h"

namespace se
{
	DataCache::DataCache()
	{
		total_bytes = 0;
		maximum_bytes = DEFAULT_MAX_RAW_BYTES;
		maximum_item_bytes = DEFAULT_MAX_ITEM_BYTES;
	}
	DataCache::DataCache(size_t _max_raw_bytes, size_t _max_item_bytes)
	{
		// debug misuse if _max_raw_bytes less than max_item_bytes

		total_bytes = 0;
		maximum_bytes = _max_raw_bytes;
		maximum_item_bytes = _max_item_bytes;
	}

	bool DataCache::retrieve(
		const std::string& _key, size_t& _bytes, void*& _data)
	{
		std::list<frame>::iterator list_element;
		std::unordered_map<std::string,
			std::list<frame>::iterator>::iterator element;
		element = data_table.find(_key);
		if (element == data_table.end())
		{
			return false;
		}
		else
		{
			list_element = element->second;
			if (list_element != priority_list.begin())
			{
				priority_list.splice(
					priority_list.begin(),
					priority_list,
					list_element,
					std::next(list_element));
			}
			_bytes = list_element->size;
			_data = list_element->data;
			return true;
		}
	}
	bool DataCache::insert(
		const std::string& _key, size_t _bytes, void* _data)
	{
		frame new_frame;
		if (_bytes > maximum_item_bytes) return false;
		total_bytes += _bytes;
		adjust();
		new_frame.size = _bytes;
		new_frame.data = malloc(_bytes); //debug error out of memory
		new_frame.key = _key;
		memcpy(new_frame.data, _data, _bytes);
		priority_list.push_front(new_frame);
		data_table[_key] = priority_list.begin();
	}
	void DataCache::set_max_raw_bytes(size_t _bytes)
	{
		// debug misuse if less than max_item_bytes
		maximum_bytes = _bytes;
		adjust();
	}
	void DataCache::set_max_item_bytes(size_t _bytes)
	{
		// debug misuse if greater than than max_raw_bytes
		maximum_item_bytes = _bytes;
	}
	void DataCache::adjust()
	{
		while(total_bytes > maximum_bytes)
		{
			total_bytes -= priority_list.back().size;
			data_table.erase(priority_list.back().key);
			priority_list.pop_back();
		}
	}
}
