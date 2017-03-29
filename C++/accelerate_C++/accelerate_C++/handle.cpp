#include "handle.h"

template <class T>
Handle<T>& Handle<T>::operator=(const Handle& rhs)
{
	++rhs.refptr;
	if (--*refpttr == 0)
	{
		delete p;
		delete refptr;
	}
	refptr = rhs.refptr;
	p = rhs.p;
	return *this;
}

template <class T>
T& Handle<T>::operator*()const
{
	if (p)
		return *p;
	throw std::runtime_error("unbound Handle");
}

template<class T>
T* Handle<T>::operator->()const
{
	if (p)
		return p;
	throw std::runtime_error("unbound Handle");
}
template<class T>
Handle<T>::~Handle()
{
	if (--*refptr == 0)
	{
		delete p;
		delete refptr;
	}
}