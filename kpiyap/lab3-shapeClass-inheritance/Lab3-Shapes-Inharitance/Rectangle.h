#pragma once
#include "TwoDShape.h"

class Rectangle :
	public TwoDShape
{
private:
	double a;
public:
	Rectangle(double line=0): TwoDShape(line), a(line)
	{
		std::cout << "***Created Rectangle\n";
	}
	Rectangle(double height, double line) : TwoDShape(height), a(line)
	{
		std::cout << "***Created Rectangle\n";
	}
	virtual ~Rectangle() override 
	{
		std::cout << "###Rectangle destroyed\n";
	}
	double virtual area() override;
	virtual std::ostream& print(std::ostream& out) const  override;
	virtual std::istream& init(std::istream& in) override;
};

