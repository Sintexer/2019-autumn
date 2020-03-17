#pragma once
#include "TwoDShape.h"
class Circle :
	public TwoDShape
{
public:
	Circle()
	{
		std::cout << "***Created Circle\n";
	}
	Circle(double radius) : TwoDShape(radius)
	{
		std::cout << "***Created Circle\n";
	}
	virtual ~Circle() override
	{
		std::cout << "###Circle destroyed\n";
	}
	double virtual area() override;
	virtual std::ostream& print(std::ostream& out) const  override;
	virtual std::istream& init(std::istream& in) override;
};


