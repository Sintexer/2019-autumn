#include "Sun.h"



std::istream& operator>>(std::istream& in, Sun& obj)
{
	in >> static_cast<Star&>(obj);
    cout << "Input system name(string): " << endl;
	safeStr(in, obj.system_name);
	return in;
}

std::ostream& operator<<(std::ostream& out, Sun& obj)
{
	return out << obj.makeStr();
}

Sun& Sun::operator=(const Sun& sn)
{
    if (*this == sn)
        return *this;
    static_cast<Star&>(*this) = static_cast<const Star&>(sn);
    this->system_name=sn.system_name;
    return *this;
}

const std::string &Sun::getSystemName() const {
    return system_name;
}

void Sun::setSystemName(const std::string &systemName) {
    system_name = systemName;
}

bool Sun::operator==(const Sun &rhs) const {
    return static_cast<const Star &>(*this) == static_cast<const Star &>(rhs) &&
           system_name == rhs.system_name;
}

bool Sun::operator!=(const Sun &rhs) const {
    return !(rhs == *this);
}

bool Sun::operator>(const Sun& rhs) const
{
	if (*this == rhs)
		return false;
	if (system_name > rhs.system_name)
		return true;
	else if (system_name == rhs.system_name) 
			return (static_cast<const Star&>(*this) > static_cast<const Star&>(rhs));
	else return false;
}

bool Sun::operator<(const Sun& rhs) const
{
	if (*this == rhs)
		return false;
	return !(*this > rhs);
}

std::string Sun::makeStr() const
{
    std::string t;
    t+=Star::makeStr();
    t+='|'+system_name;
    return t;
}

std::string Sun::makeTableHead() const {
    return  Star::makeTableHead() + std::string("|System:");
}

std::string Sun::className() const
{
    return std::string ("Sun");
}

void Sun::print() {
    cout << *this;
}

void Sun::input() {
    cin >> *this;
}
