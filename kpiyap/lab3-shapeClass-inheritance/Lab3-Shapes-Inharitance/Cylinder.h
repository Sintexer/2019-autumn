#pragma once
#include "ThreeDShape.h"
class Cylinder :
	public ThreeDShape
{
private:
	double r;
public:
	Cylinder(double line = 0) : ThreeDShape(line), r(line)
	{
		std::cout << "***Created Cylinder\n";
	}
	Cylinder(double height, double radius) : ThreeDShape(height), r(radius)
	{
		std::cout << "***Created Cylinder\n";
	}
	virtual ~Cylinder() override
	{
		std::cout << "###Cylinder destroyed\n";
	}
	double virtual area() override;
	double virtual volume() override;
	virtual std::ostream& print(std::ostream& out) const  override;
	virtual std::istream& init(std::istream& in) override;

};

