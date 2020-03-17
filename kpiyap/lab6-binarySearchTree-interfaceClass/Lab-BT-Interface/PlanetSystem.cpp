#include "PlanetSystem.h"

Planet& PlanetSystem::operator[] (size_t index)
{
    return PlanetRow::operator[](index);
}

std::ostream& operator<< (std::ostream& out, PlanetSystem& obj)
{
	return out << obj.Sun::makeTableHead() << endl << obj.Sun::makeStr() << endl
	<< obj.PlanetRow::makeTableHead() << endl << obj.PlanetRow::makeStr();
}

void PlanetSystem::print() {
    cout << *this;
}
