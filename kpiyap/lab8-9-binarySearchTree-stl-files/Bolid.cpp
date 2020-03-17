#include "Bolid.h"

std::istream& operator>> (std::istream& in, Bolid& obj)
{
	in >> static_cast<Meteor&>(obj);
    cout << "Input sound power(double): " << endl;
	inputSafe(in, obj.sound_power);
	return in;
}

std::ostream& operator<< (std::ostream& out, Bolid& obj)
{
    return out << static_cast<Meteor&>(obj) << obj.sound_power << '|';
}

Bolid& Bolid::operator=(const Bolid& bld)
{
    if (*this==bld)
        return *this;
    static_cast<Bolid&>(*this)=static_cast<const Bolid&>(bld);
    this->sound_power=bld.sound_power;
    return *this;
}

bool Bolid::operator==(const Bolid& rhs) const {
	return static_cast<const Meteor&>(*this) == static_cast<const Meteor&>(rhs) &&
		sound_power == rhs.sound_power;
}

bool Bolid::operator!=(const Bolid& rhs) const {
	return !(rhs == *this);
}

bool Bolid::operator>(const Bolid& rhs) const
{
	if (*this == rhs)
		return false;
	if (sound_power > rhs.sound_power)
		return true;
	else if (sound_power == rhs.sound_power)
		return (static_cast<const Meteor&>(*this) > static_cast<const Meteor&>(rhs));
	else return false;
}

bool Bolid::operator<(const Bolid& rhs) const
{
	if (*this == rhs)
		return false;
	return !(*this > rhs);
}


double Bolid::getSoundPower() const {
    return sound_power;
}

void Bolid::setSoundPower(double soundPower) {
    sound_power = soundPower;
}

std::string Bolid::makeStr() const
{
    std::string t;
    t+=Meteor::makeStr();
    t+='|'+d_to_str(sound_power);
    return t;
}

std::string Bolid::makeTableHead() const {
    return Meteor::makeTableHead() + std::string("|Sound pw:");
}

std::string Bolid::className() const
{
    return std::string ("Bolid");
}

void Bolid::print() {
    cout << *this;
}

void Bolid::input() {
    cin >> *this;
}

std::ifstream &operator>>(std::ifstream &in, Bolid &obj) {
    in >> obj.mass;
    in.get();
    in >> obj.volume;
    in.get();
    in >> obj.temp;
    in.get();
    getline(in, obj.metal, '|');
    in >> obj.height;
    in.get();
    in >> obj.distance;
    in.get();
    in >> obj.sound_power;
    in.get();
    return in;
}

string Bolid::getPath() {
    return "Bolid.txt";
}

string Bolid::getPathBinary() {
    return "Bolid.bin";
}

void Bolid::writeBin(BinaryFile& bin) {
    Meteor::writeBin(bin);
    bin.write(sound_power);
}

bool Bolid::readBin(BinaryFile &bin) {
    if(!bin.in())
        return false;
    Meteor::readBin(bin);
    bin.read(sound_power);
    return true;
}