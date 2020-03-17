#pragma once
#include "Shape.h"
class ThreeDShape :
	public Shape
{
protected:
	double h;
public:
	ThreeDShape() : h(0)
	{
		std::cout << "***Created 3DShape\n";
	}
	ThreeDShape(double height) : h(height)
	{
		std::cout << "***Created 3DShape\n";
	}
	virtual ~ThreeDShape()
	{
		std::cout << "###3DShape destroyed\n";
	}
	double virtual area() = 0;
	double virtual volume() = 0;
	virtual std::ostream& print(std::ostream& out) const = 0;
	virtual std::istream& init(std::istream& in) = 0;
};

