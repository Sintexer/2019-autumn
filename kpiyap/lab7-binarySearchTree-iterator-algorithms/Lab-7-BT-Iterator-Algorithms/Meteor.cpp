#include "Meteor.h"

std::istream& operator>> (std::istream& in, Meteor& obj)
{
	in >> static_cast<Asteroid&>(obj);
    cout << "Input height(double): " << endl;
	inputSafe(in, obj.height);
    cout << "Input distance(double): " << endl;
	inputSafe(in, obj.distance);
	return in;
}

std::ostream& operator<< (std::ostream& out, Meteor& obj)
{
	return out << obj.makeStr();
}

Meteor& Meteor::operator=(const Meteor& metr)
{
    if (*this==metr)
        return *this;
    static_cast<Asteroid&>(*this)= static_cast<const Asteroid&>(metr);
    height=metr.height;
    distance=metr.distance;
    return *this;
}

double Meteor::getHeight() const {
    return height;
}

void Meteor::setHeight(double height) {
    Meteor::height = height;
}

double Meteor::getDistance() const {
    return distance;
}

void Meteor::setDistance(double distance) {
    Meteor::distance = distance;
}

bool Meteor::operator==(const Meteor &rhs) const {
    return static_cast<const Asteroid &>(*this) == static_cast<const Asteroid &>(rhs) &&
           height == rhs.height &&
           distance == rhs.distance;
}

bool Meteor::operator!=(const Meteor &rhs) const {
    return !(rhs == *this);
}

bool Meteor::operator>(const Meteor& rhs) const
{
	if (*this == rhs)
		return false;
	if (height > rhs.height)
		return true;
	else if (height == rhs.height)
		if (distance > rhs.distance)
			return true;
		else if (distance == rhs.distance)
			return (static_cast<const Asteroid&>(*this) > static_cast<const Asteroid&>(rhs)); \
		else return false;
	else return false;
}

bool Meteor::operator<(const Meteor& rhs) const
{
	if (*this == rhs)
		return false;
	return !(*this > rhs);
}

std::string Meteor::makeStr() const
{
    std::string t;
    t+=Asteroid::makeStr();
    t+='|'+d_to_str(height);
    t+='|'+d_to_str(distance);
    return t;
}

std::string Meteor::makeTableHead() const {
    return Asteroid::makeTableHead() + std::string("|Height:|Distance:");
}

std::string Meteor::className() const
{
    return std::string ("Meteor");
}

void Meteor::print() {
    cout  << *this;
}

void Meteor::input() {
    cin >> *this;
}
