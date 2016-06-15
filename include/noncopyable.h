#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H

namespace se
{
	class NonCopyable
	{
	public:
		NonCopyable() { };
		NonCopyable(const NonCopyable&) = delete;
		const NonCopyable& operator=(const NonCopyable&) = delete;
	};
}

#endif