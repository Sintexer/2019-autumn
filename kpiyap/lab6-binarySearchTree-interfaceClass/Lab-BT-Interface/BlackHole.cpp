#include "BlackHole.h"

std::istream& operator>> (std::istream& in, BlackHole& obj)
{
    cout << "Input volume(double): " << endl;
	inputSafe(in, obj.volume);
    cout << "Input temperature(double): " << endl;
	inputSafe(in, obj.temp);
    cout << "Input Black Hole type(string): " << endl;
	safeStr(in, obj.type);
	return in;
}

std::ostream& operator<< (std::ostream& out, BlackHole& obj)
{
	return out << obj.makeStr();
}

BlackHole& BlackHole::operator= (const BlackHole& bh)
{
    if (*this==bh)
        return *this;
    static_cast<SpaceObject&>(*this)= static_cast<const SpaceObject&>(bh);
    this->type=bh.type;
    return *this;
}

const std::string &BlackHole::getType() const {
    return type;
}

void BlackHole::setType(const std::string &type) {
    BlackHole::type = type;
}

bool BlackHole::operator==(const BlackHole &rhs) const {
    return static_cast<const SpaceObject &>(*this) == static_cast<const SpaceObject &>(rhs) &&
           type == rhs.type;
}

bool BlackHole::operator!=(const BlackHole &rhs) const {
    return !(rhs == *this);
}

bool BlackHole::operator>(const BlackHole& rhs) const
{
	if (*this == rhs)
		return false;
	if (type > rhs.type)
		return true;
	else 
		if (type == rhs.type)
			return (static_cast<const SpaceObject&>(*this) > static_cast<const SpaceObject&>(rhs));
	else return false;
}

bool BlackHole::operator<(const BlackHole& rhs) const
{
	if (*this == rhs)
		return false;
	return !(*this > rhs);
}

std::string BlackHole::makeStr() const{
    std::string s(className());
    return s+'|'+"Infinity"+'|'+d_to_str(volume)+'|'+d_to_str(temp);
}

std::string BlackHole::makeTableHead() const {
    return std::string("Mass:|Volume:|Temperature:");
}

std::string BlackHole::className() const{
    std::string s(type);
    return s+" Blackhole";
}

void BlackHole::print() {
    cout << *this;
}

void BlackHole::input() {
    cin >> *this;
}
