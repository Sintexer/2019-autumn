#include "Cylinder.h"

double Cylinder::area()
{
	return Constant::PI*r*r+2*Constant::PI*h;
}

double Cylinder::volume()
{
	return Constant::PI * r * r * h;
}

std::ostream& Cylinder::print(std::ostream& out) const
{
	return (out << "Cylinder h= " << h << ", r= " << r);
}

std::istream& Cylinder::init(std::istream& in)
{
	return (in >> h >> r);
}
