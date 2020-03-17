#include "Sphere.h"

double Sphere::area()
{
	return 4*Constant::PI*h*h;
}

double Sphere::volume()
{
	return 4 / 3 * Constant::PI * h * h * h;
}

std::ostream& Sphere::print(std::ostream& out) const
{
	return (out << "Sphere r= " << h);
}

std::istream& Sphere::init(std::istream& in)
{
	return (in >> h);
}