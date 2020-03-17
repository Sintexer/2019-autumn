#include "Comet.h"

std::istream& operator>> (std::istream& in, Comet& obj)
{
	in >> static_cast<Asteroid&>(obj);
    cout << "Input tail composition(string): " << endl;
	safeStr(in, obj.tail_composition);
    cout << "Input tail length(double): " << endl;
	inputSafe(in, obj.tail_length);
	return in;
}

std::ostream& operator<< (std::ostream& out, Comet& obj)
{
	return out << static_cast<Asteroid&>(obj) << obj.tail_composition << "|" << obj.tail_length << "|";
}

Comet& Comet::operator=(const Comet& cmt)
{
    if (*this==cmt)
        return *this;
    static_cast<Asteroid&>(*this)=static_cast<const Asteroid&>(cmt);
    this->tail_composition=cmt.tail_composition;
    this->tail_length=cmt.tail_length;
    return *this;
}

void Comet::setTailComposition(const std::string &tailComposition) {
    tail_composition = tailComposition;
}

void Comet::setTailLength(double tailLength) {
    tail_length = tailLength;
}

const std::string &Comet::getTailComposition() const {
    return tail_composition;
}

double Comet::getTailLength() const {
    return tail_length;
}

bool Comet::operator==(const Comet &rhs) const {
    return static_cast<const Asteroid &>(*this) == static_cast<const Asteroid &>(rhs) &&
           tail_composition == rhs.tail_composition &&
           tail_length == rhs.tail_length;
}

bool Comet::operator!=(const Comet &rhs) const {
    return !(rhs == *this);
}

bool Comet::operator>(const Comet& rhs) const
{
	if (*this == rhs)
		return false;
	if (tail_composition > rhs.tail_composition)
		return true;
	else if (tail_composition == rhs.tail_composition)
		if (tail_length > rhs.tail_length)
			return true;
		else if (tail_length == rhs.tail_length)
			return (static_cast<const Asteroid&>(*this) > static_cast<const Asteroid&>(rhs));
		else return false;
	else return false;
}

bool Comet::operator<(const Comet& rhs) const
{
	if (*this == rhs)
		return false;
	return !(*this > rhs);
}

std::string Comet::makeStr() const
{
    std::string t;
    t+=Asteroid::makeStr();
    t+='|'+tail_composition;
    t+='|'+d_to_str(tail_length);
    return t;
}

std::string Comet::makeTableHead() const {
    return Asteroid::makeTableHead() + std::string("|Tail comp. :|Tail len. :");
}

std::string Comet::className() const
{
    return std::string ("Comet");
}

void Comet::print() {
    cout << *this;
}

void Comet::input() {
    cin >> *this;
}

std::ifstream &operator>>(std::ifstream &in, Comet &obj) {
    in >> obj.mass;
    in.get();
    in >> obj.volume;
    in.get();
    in>> obj.temp;
    in.get();
    getline(in, obj.metal, '|');
    getline(in, obj.tail_composition, '|');
    in>> obj.tail_length;
    in.get();
    return in;
}

string Comet::getPath() {
    return "Comet.txt";
}

string Comet::getPathBinary() {
    return "Comet.bin";
}

void Comet::writeBin(BinaryFile& bin) {
    Asteroid::writeBin(bin);
    size_t size{tail_composition.length()};
    bin.write(size);
    bin.writeLine(tail_composition);
    bin.write(tail_length);
}

bool Comet::readBin(BinaryFile &bin) {
    if(!bin.in())
        return false;
    Asteroid::readBin(bin);
    size_t size{};
    bin.read(size);
    tail_composition.clear();
    tail_composition.reserve(size);
    bin.readLine(tail_composition, size);
    bin.read(tail_length);
    return true;
}