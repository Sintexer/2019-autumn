#pragma once
#include"TwoDShape.h"

class Triangle: 
	public TwoDShape
{
private:
	double a;
public:
	Triangle(double line=0): TwoDShape(line),  a(line)
	{
		std::cout << "***Created Triangle\n";
	}
	Triangle(double height, double line) : TwoDShape(height), a(line)
	{
		std::cout << "***Created Triangle\n";
	}
	virtual ~Triangle() override
	{
		std::cout << "###Triangle destroyed\n";
	}
	double virtual area() override;
	virtual std::ostream& print(std::ostream& out) const  override;
	virtual std::istream& init(std::istream& in) override;
};

