#include "Shape.h"

std::ostream& operator<< (std::ostream& out, Shape& shape) 
{
	return shape.print(out);
}

std::istream& operator>> (std::istream& in, Shape& shape)
{
	return shape.init(in);
}