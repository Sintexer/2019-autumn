#pragma once
#include "ThreeDShape.h"
class Sphere :
	public ThreeDShape
{
public:
	Sphere()
	{
		std::cout << "***Sphere Cylinder\n";
	}
	Sphere(double radius) : ThreeDShape(radius)
	{
		std::cout << "***Created Sphere\n";
	}
	virtual ~Sphere() override
	{
		std::cout << "###Sphere destroyed\n";
	}
	double virtual area() override;
	double virtual volume() override;
	virtual std::ostream& print(std::ostream& out) const  override;
	virtual std::istream& init(std::istream& in) override;
};

