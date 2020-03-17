#include "Planet.h"

std::istream& operator>> (std::istream& in, Planet& obj)
{
	in >> static_cast<SpaceObject&>(obj);
    cout << "Input rotation speed(double): " << endl;
	inputSafe(in, obj.rotation_speed);
    cout << "Input g(double): " << endl;
	inputSafe(in, obj.g);
    cout << "Input day length(double): " << endl;
	inputSafe(in, obj.day_length);
    cout << "Input number of satelites(int): " << endl;
	inputSafe(in, obj.number_of_satelites);
    cout << "Input planet name(string): " << endl;
	safeStr(in, obj.planet_name);
	return in;
}

std::ostream& operator<< (std::ostream& out, const Planet& obj)
{
	return out << obj.makeStr();
}

Planet& Planet::operator=(const Planet& pl)
{
    if (*this==pl)
        return *this;
    static_cast<SpaceObject&>(*this) = static_cast<const SpaceObject &>(pl);
    this->rotation_speed=pl.rotation_speed;
    this->g=pl.g;
    this->day_length=pl.day_length;
    this->number_of_satelites=pl.number_of_satelites;
    this->planet_name=pl.planet_name;
    return *this;
}

bool Planet::operator==(const Planet &rhs) const {
    return static_cast<const SpaceObject &>(*this) == static_cast<const SpaceObject &>(rhs) &&
           rotation_speed == rhs.rotation_speed &&
           g == rhs.g &&
           day_length == rhs.day_length &&
           number_of_satelites == rhs.number_of_satelites &&
           planet_name == rhs.planet_name;
}

bool Planet::operator!=(const Planet &rhs) const {
    return !(rhs == *this);
}

bool Planet::operator>(const Planet& rhs) const
{
	if (*this == rhs)
		return false;
	if (planet_name > rhs.planet_name)
		return true;
	else if (planet_name == rhs.planet_name) {
		if (number_of_satelites > rhs.number_of_satelites)
			return true;
		else if (number_of_satelites == rhs.number_of_satelites)
			return (static_cast<const SpaceObject&>(*this) > static_cast<const SpaceObject&>(rhs));
		else
			return false;
	}
	else return false;
}

bool Planet::operator<(const Planet& rhs) const
{
	if (*this == rhs)
		return false;
	return !(*this > rhs);
}

double Planet::getRotationSpeed() const {
    return rotation_speed;
}

double Planet::getG() const {
    return g;
}

double Planet::getDayLength() const {
    return day_length;
}

int Planet::getNumberOfSatelites() const {
    return number_of_satelites;
}

const std::string &Planet::getPlanetName() const {
    return planet_name;
}

void Planet::setRotationSpeed(double rs) {
	rotation_speed = rs;
}

void Planet::setG(double gt)  {
	g= gt;
}

void Planet::setDayLength(double dsl)  {
	day_length = dsl;
}

void Planet::setNumberOfSatelites(int nos)  {
	number_of_satelites = nos;
}

void Planet::setPlanetName(std::string pn)  {
	planet_name = pn;
}

std::string Planet::makeStr() const
{
    std::string t;
    t+=SpaceObject::makeStr();
    t+='|'+d_to_str(rotation_speed);
    t+='|'+d_to_str(g);
    t+='|'+d_to_str(day_length);
    t+='|'+std::to_string(number_of_satelites);
	t += '|' + planet_name;
    return t;
}

std::string Planet::makeTableHead() const {
    return SpaceObject::makeTableHead() + std::string("|Rot. speed:|G:|Day last:|Satelites:|Name:");
}

std::string Planet::className() const
{
    std::string s("Planet");
	return s;//+=planet_name;
}

void Planet::print() {
    cout << *this;
}

void Planet::input() {
    cin >> *this;
}
