#ifndef CORE_H
#define CORE_H

template <typename T>
class ReadOnlyProperty {
public:
	virtual ~ReadOnlyProperty() {}
	virtual operator T const& () const { return value; }
	virtual T& operator() () { return value; }
	virtual T const& operator() () const { return value; }
protected:
	T value;
};
#define SE_CORE_READONLY_PROPERTY(_CLASS_, _TYPE_, _PROP_) \
	class : public ReadOnlyProperty<_TYPE_> { friend class _CLASS_; } _PROP_;

namespace se
{
	extern const char* VERSION_STRING;


}

#endif