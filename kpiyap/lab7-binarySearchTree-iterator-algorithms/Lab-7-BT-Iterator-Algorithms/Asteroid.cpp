#include "Asteroid.h"

std::istream& operator>> (std::istream& in, Asteroid& obj)
{
    in >> static_cast<SpaceObject&>(obj);
    cout << "Input metal(string): " << endl;
	safeStr(in, obj.metal);
    return in;
}
std::ostream& operator<< (std::ostream& out, Asteroid& obj)
{
	return out << obj.makeStr();
}

const std::string &Asteroid::getMetal() const {
    return metal;
}
void Asteroid::setMetal(const std::string &met) {
    Asteroid::metal = met;
}

Asteroid& Asteroid::operator=(const Asteroid& astr)
{
    if (*this==astr)
        return *this;
    static_cast<SpaceObject&>(*this)=static_cast<const SpaceObject&>(astr);
    this->metal=astr.metal;
    return *this;
}

bool Asteroid::operator==(const Asteroid &astr) const {
    return static_cast<const SpaceObject &>(*this) == static_cast<const SpaceObject &>(astr) &&
           metal == astr.metal;
}
bool Asteroid::operator!=(const Asteroid &astr) const {
    return !(astr == *this);
}

bool Asteroid::operator>(const Asteroid& astr) const
{
	if (*this == astr)
		return false;
	if (metal > astr.metal)
		return true;
	else if (metal == astr.metal)
		return (static_cast<const SpaceObject&>(*this) > static_cast<const SpaceObject&>(astr));
	else return false;
}

bool Asteroid::operator<(const Asteroid& astr) const
{
	if (*this == astr)
		return false;
	return !(*this > astr);
}

std::string Asteroid::makeStr() const
{
    std::string t;
    t+=SpaceObject::makeStr();
    t+='|'+metal;
    return t;
}

std::string Asteroid::makeTableHead() const {
    return SpaceObject::makeTableHead() + std::string("|Metal:");
}

std::string Asteroid::className() const
{
    return std::string("Asteroid");
}

void Asteroid::print() {
    cout << *this;
}

void Asteroid::input() {
    cin >> *this;
}
