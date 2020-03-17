#include "SpaceObject.h"


std::string d_to_str(double d){
    int e = 0;
    bool less_then_zero = false;
    if (d<0){
        less_then_zero=true;
        d*=-1;
    }
    if(d>100)
        while (d > 1000)
        {
            d/=10;
            ++e;
        }
    else
        while (d < 1)
        {
            d*=10;
            --e;
        }
        if (less_then_zero)
            d*=-1;
    std::string temp(std::to_string(d));
    return temp+'e'+std::to_string(e);
}

std::ostream& operator<<(std::ostream& out, const SpaceObject& obj)
{
	return out << obj.mass << "|" << obj.volume << "|" << obj.temp << "|";
}

std::istream& operator>>(std::istream& in, SpaceObject& obj)
{
    cout << "Input mass(double): " << endl;
	inputSafe(in, obj.mass, 0, pow(sizeof(double), 8));
    cout << "Input volume(double): " << endl;
	inputSafe(in, obj.volume, 0, pow(sizeof(double), 8));
    cout << "Input temperature(double): " << endl;
	inputSafe(in, obj.temp, 0, pow(sizeof(double), 8));
	return in;
}

void SpaceObject::setMass(double mass) {
    SpaceObject::mass = mass;
}

void SpaceObject::setVolume(double volume) {
    SpaceObject::volume = volume;
}

void SpaceObject::setTemp(double temp) {
    SpaceObject::temp = temp;
}

double SpaceObject::getMass() const {
    return mass;
}

double SpaceObject::getVolume() const {
    return volume;
}

double SpaceObject::getTemp() const {
    return temp;
}

bool SpaceObject::operator==(const SpaceObject &rhs) const {
    return mass == rhs.mass &&
           volume == rhs.volume &&
           temp == rhs.temp;
}

bool SpaceObject::operator!=(const SpaceObject &rhs) const {
    return !(rhs == *this);
}

bool SpaceObject::operator>(const SpaceObject& rhs) const
{
	if (*this == rhs)
		return false;
	if (mass > rhs.mass)
		return true;
	else if (mass == rhs.mass) {
		if (volume > rhs.volume)
			return true;
		else if (volume == rhs.volume)
			return temp > rhs.temp;
		else return false;
	}
	else return false;
}

bool SpaceObject::operator<(const SpaceObject& rhs) const
{
	if (*this == rhs)
		return false;
	return !(*this > rhs);
}

SpaceObject& SpaceObject::operator=(const SpaceObject& so) {
    if (*this==so)
        return *this;
    this->mass=so.mass;
    this->volume=so.volume;
    this->temp=so.temp;
    return *this;
}

std::string SpaceObject::makeStr() const
{
    std::string t;
    t+=className() +'|';
    t+=d_to_str(mass) + '|';
    t+=d_to_str(volume) + '|';
    t+=d_to_str(temp);
    return t;
}

std::string SpaceObject::makeTableHead() const
{
    return std::string("Mass:|Volume:|Temperature:");
}

std::string SpaceObject::className() const
{
    return std::string("SpaceObject");
}

void SpaceObject::input() {
    cin >> *this;
}

void SpaceObject::print() {
    cout << *this;
}

string SpaceObject::getPath() {
    return "output.txt";
}

string SpaceObject::getPathBinary() {
    return "output.bin";
}

void SpaceObject::writeBin(BinaryFile &bin) {
    return;
}

bool SpaceObject::readBin(BinaryFile &bin) {
    return true;
}