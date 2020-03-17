#pragma once
#include "Shape.h"

class TwoDShape: 
	public Shape
{
protected:
	double h;
public:
	TwoDShape(): h(0)
	{
		std::cout << "***Created 2DShape\n";
	}
	TwoDShape(double height) : h(height)
	{
		std::cout << "***Created 2DShape\n";
	}
	virtual ~TwoDShape()
	{
		std::cout << "###2DShape destroyed\n";
	}
	double virtual area() = 0;
	virtual std::ostream& print(std::ostream& out) const = 0;
	virtual std::istream& init(std::istream& in) = 0;
};

