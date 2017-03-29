#pragma once

#include "stdafx.h"

class Student_info
{
public:
	Student_info(){}
	Student_info(std::istream& is) { read(is); }

	std::istream& read(std::istream&);
	inline std::string name()const
	{
		if (cp) return cp->name();
		else throw std::runtime_error("unintialized student");
	}
	inline double grade()
	{
		if (cp) return cp->grade();
		else throw std::runtime_error("unintialized student");
	}
	inline static bool compare(const Student_info& s1, const Student_info& s2)
	{
		return s1.name() < s2.name();
	}
private:
	Handle<Core> cp;
};