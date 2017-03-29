#include "core.h"

std::string Core::name()const
{
	return n;
}

double Core::grade()const
{
 	std::sort(homework.begin(), homework.end());
	auto tmp = homework[homework.size / 2];
	
	auto f = [](double midterm, double final, double tmp) {return midterm + final + tmp;};	
	return f(midterm, final, tmp);
}

std::istream& Core::read_common(std::istream& in)
{
	in >> n >> midterm >> final;
	return in;
}
std::istream& Core::read(std::istream& in)
{
	read_common(in);
	read_hw(in, homework);
	return in;
}


std::istream& Grad::read(std::istream& in)
{
	read_common(in);
	in >> thesis;
	read_hw(in, homework);
	return in;
}

double Grad::grade()const
{
	return std::min(Core::grade(), thesis);	
}

