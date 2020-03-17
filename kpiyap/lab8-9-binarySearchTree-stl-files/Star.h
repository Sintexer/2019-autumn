#pragma once
#include "SpaceObject.h"
class Star :
	public SpaceObject
{
protected:
	double luminosity;
	double age;
	std::string colour;
public:
	Star() : SpaceObject(), luminosity(0), age(0), colour("None"){}
	Star(const Star& st) = default;
	Star(double mass, double volume, double  temp, double l, double a, std::string clr) :SpaceObject(mass, volume, temp),
		luminosity(l), age(a), colour(clr){}
	~Star() override = default;

    void print() override;

    void input() override;

    friend std::istream& operator>> (std::istream& in, Star& obj);
	friend std::ostream& operator<< (std::ostream& out, Star& obj);
    friend std::ifstream& operator>>(std::ifstream &in, Star &obj);

    string getPath() override;
    string getPathBinary() override ;

	Star& operator=(const Star& st);

    void setLuminosity(double luminosity);
    void setAge(double age);
    void setColour(const std::string &colour);
    double getLuminosity() const;
    double getAge() const;
    const std::string &getColour() const;

    bool operator==(const Star &rhs) const;
    bool operator!=(const Star &rhs) const;
	bool operator>(const Star& rhs) const;
	bool operator<(const Star& rhs) const;

    std::string makeStr() const override ;
    std::string makeTableHead() const override;

    std::string className() const override;

    void writeBin(BinaryFile& bin) override ;
    bool readBin(BinaryFile& bin) override ;
};
