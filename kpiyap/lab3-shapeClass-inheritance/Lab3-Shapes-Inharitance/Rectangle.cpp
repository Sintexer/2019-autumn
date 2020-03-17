#include "Rectangle.h"

double Rectangle::area()
{
	return a * h;
}

std::ostream& Rectangle::print(std::ostream& out) const
{
	return (out << "Rectangle h= " << h << ", a= " << a);
}

std::istream& Rectangle::init(std::istream& in)
{
	return (in >> h >> a);
}