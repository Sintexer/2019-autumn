#include "Triangle.h"
#include <cmath>

double Triangle::area()
{
	return a * h / 2;
}

std::ostream& Triangle::print(std::ostream& out) const
{
	return (out << "Triangle h= " << h << ", a= " << a);
}

std::istream& Triangle::init(std::istream& in)
{
	return (in >> h >> a);
}

