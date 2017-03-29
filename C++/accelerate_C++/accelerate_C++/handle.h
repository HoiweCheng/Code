#pragma once
#include "stdafx.h"


template <class T> class Handle
{
public:
	Handle() :p(0), refptr(1) {}
	Handle(T* t):p(t), refptr(1){}
	Handle(const Handle& s) :p(s.p), refptr(s.refprt) { ++refptr; }
	Handle& operator = (const Handle&);
	~Handle();

	Handle(T* t):p(t){ }

	operator bool() const { return p; }
	T& operator *() const;
	T* operator ->() const;

private:
	T* p;
	std::size_t* refptr;
};