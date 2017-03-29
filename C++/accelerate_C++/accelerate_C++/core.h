#pragma once
#include "stdafx.h"

class Core
{
public:
	Core() : midterm(0), final(0){};
	Core(std::istream& is) { read(is); }
	std::string name()const;
	virtual std::istream& read(std::istream&);
	virtual double grade()const;
protected:
	std::istream& read_common(std::istream&);	
	double midterm, final;
	std::vector<double> homework;
	std::istream& read_hw(std::istream&, std::vector<double> homework);
private:
	std::string n;
	
};

class Grad: public Core
{
	friend class Student_info;
public:
	Grad():thesis(0){}
	Grad(std::istream& is) { read(is); }
	virtual double grade()const;
	std::istream& read(std::istream&);
private:
	double thesis;
};

bool compare(const Core&, const Core&);