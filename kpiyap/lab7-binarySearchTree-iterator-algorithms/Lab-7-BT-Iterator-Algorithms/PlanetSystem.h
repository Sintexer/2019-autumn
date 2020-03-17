#pragma once
#include "Sun.h"
#include "PlanetRow.h"
class PlanetSystem : public Sun, public PlanetRow
{
protected:
public:
	PlanetSystem() :Sun(), PlanetRow(){}
	PlanetSystem(Sun& sn, PlanetRow& pr) :Sun(sn), PlanetRow(pr){}
	~PlanetSystem() override = default;

    Planet& operator[] (size_t index) override;

    void print() override;

    friend std::ostream& operator<< (std::ostream& out, PlanetSystem& obj);
};

