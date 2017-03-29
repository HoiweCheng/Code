#include "student_info.h"

std::istream& Student_info::read(std::istream& is)
{
	char ch;
	is >> ch;
	if (ch == 'U')
		cp = new Core(is);
	else
		cp = new Grad(is);

	return is;
}

