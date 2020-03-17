#include "Star.h"

std::istream& operator>> (std::istream& in, Star& obj)
{
	in >> static_cast<SpaceObject&>(obj);
    cout << "Input luminosity(double): " << endl;
	inputSafe(in, obj.luminosity, 0, pow(sizeof(double), 8));
    cout << "Input star age(double): " << endl;
	inputSafe(in, obj.age, 0, pow(sizeof(double), 8));
    cout << "Input colour(string): " << endl;
	safeStr(in, obj.colour);
	return in;
}

std::ostream& operator<< (std::ostream& out, Star& obj)
{
	return out << obj.makeStr();
}

Star& Star::operator=(const Star& st)
{
    if (*this==st)
        return *this;
    static_cast<SpaceObject&>(*this) = static_cast<const SpaceObject&>(st);
    this->luminosity = st.luminosity;
    this->age = st.age;
    this->colour = st.colour;
    return *this;
}

void Star::setLuminosity(double luminosity) {
    Star::luminosity = luminosity;
}

void Star::setAge(double age) {
    Star::age = age;
}

void Star::setColour(const std::string &colour) {
    Star::colour = colour;
}

double Star::getLuminosity() const {
    return luminosity;
}

double Star::getAge() const {
    return age;
}

const std::string &Star::getColour() const {
    return colour;
}

bool Star::operator==(const Star &rhs) const {
    return static_cast<const SpaceObject &>(*this) == static_cast<const SpaceObject &>(rhs) &&
           luminosity == rhs.luminosity &&
           age == rhs.age &&
           colour == rhs.colour;
}

bool Star::operator!=(const Star &rhs) const {
    return !(rhs == *this);
}

bool Star::operator>(const Star& rhs) const
{
	if (*this == rhs)
		return false;
	if (colour > rhs.colour)
		return true;
	else if (colour == rhs.colour) {
		if (age > rhs.age)
			return true;
		else if (age == rhs.age)
			if (luminosity > rhs.luminosity)
				return true;
			else if (luminosity == rhs.luminosity)
				return (static_cast<const SpaceObject&>(*this) > static_cast<const SpaceObject&>(rhs));
			else return false;
		else return false;
	}
	else return false;
}

bool Star::operator<(const Star& rhs) const
{
	if (*this == rhs)
		return false;
	return !(*this > rhs);
}

std::string Star::makeStr() const
{
    std::string t;
    t+=SpaceObject::makeStr();
    t+='|'+d_to_str(luminosity);
    t+='|'+d_to_str(age);
    t+='|'+colour;
    return t;
}

std::string Star::makeTableHead() const {
    return SpaceObject::makeTableHead() + std::string("|Luminosity:|Age:|Colour:");
}

std::string Star::className() const
{
    return std::string ("Star");
}

void Star::print() {
    cout << *this;
}

void Star::input() {
    cin >> *this;
}
