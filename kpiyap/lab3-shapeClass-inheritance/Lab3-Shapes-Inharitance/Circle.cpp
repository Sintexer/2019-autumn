#include "Circle.h"
#include <cmath>

double Circle::area()
{
	return Constant::PI*h*h;
}

std::ostream& Circle::print(std::ostream& out) const
{
	return (out << "Circle r= " << h );
}

std::istream& Circle::init(std::istream& in)
{
	return (in >> h);
}
