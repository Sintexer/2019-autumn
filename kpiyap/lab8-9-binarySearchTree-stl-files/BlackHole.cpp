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
	return out << obj.volume << "|" << obj.temp << "|" << obj.type << "|";
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
    return s+'|'+d_to_str(volume)+'|'+d_to_str(temp)+'|'+type;
}

std::string BlackHole::makeTableHead() const {
    return std::string("Volume:|Temperature:|Type:");
}

std::string BlackHole::className() const{
    std::string s(type);
	return s;
}

void BlackHole::print() {
    cout << *this;
}

void BlackHole::input() {
    cin >> *this;
}

std::ifstream &operator>>(std::ifstream &in, BlackHole &obj) {
    in >> obj.volume;
    in.get();
    in>> obj.temp;
    in.get();
    getline(in, obj.type, '|');
    return in;
}

string BlackHole::getPath() {
    return "BlackHole.txt";
}

string BlackHole::getPathBinary() {
    return "BlackHole.bin";
}

void BlackHole::writeBin(BinaryFile& bin) {
    bin.write(volume);
    bin.write(temp);
    size_t size{type.length()};
    bin.write(size);
    bin.writeLine(type);
}

bool BlackHole::readBin(BinaryFile &bin) {
    if(!bin.in())
        return false;
    bin.read(volume);
    bin.read(temp);
    size_t size{};
    bin.read(size);
    type.clear();
    type.reserve(size);
    bin.readLine(type, size);
    return true;
}