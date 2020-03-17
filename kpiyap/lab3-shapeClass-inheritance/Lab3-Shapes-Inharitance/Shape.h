#pragma once
#include <iostream>
namespace Constant
{
	const long double PI = 3.141592653589793238462643383279;
	const double rad = 180 / PI;
}

class Shape
{
public:	
	Shape()
	{
		std::cout << "***Created Shape\n";
	}
	virtual ~Shape()
	{
		std::cout << "###Shape destroyed\n";
	}
	double virtual area() = 0;
	virtual std::ostream& print(std::ostream& out) const = 0;
	virtual std::istream& init(std::istream& in) = 0;
	friend std::ostream& operator<< (std::ostream& out, Shape& shape);
	friend std::istream& operator>> (std::istream& in, Shape& shape);
};

