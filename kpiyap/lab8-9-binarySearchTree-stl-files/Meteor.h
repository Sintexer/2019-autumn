#pragma once
#include "Asteroid.h"
class Meteor :
	public Asteroid
{
protected:
	double height;
	double distance;
public:
	Meteor() : Asteroid(), height(0), distance(0){}
	Meteor(const Meteor& metr) = default;
	Meteor(double m, double v, double t, std::string me, double h, double d) :
		Asteroid(m, v, t, me), height(h), distance(d){}
	~Meteor() override = default;

    void print() override;
    void input() override;

    friend std::istream& operator>> (std::istream& in, Meteor& obj);
	friend std::ostream& operator<< (std::ostream& out, Meteor& obj);
	friend  std::ifstream& operator>> (std::ifstream& in, Meteor& obj);

    string getPath() override;
    string getPathBinary() override;

	Meteor& operator=(const Meteor& metr);

    double getHeight() const;
    void setHeight(double height);
    double getDistance() const;
    void setDistance(double distance);

    bool operator==(const Meteor &rhs) const;
    bool operator!=(const Meteor &rhs) const;
	bool operator>(const Meteor& rhs) const;
	bool operator<(const Meteor& rhs) const;

    std::string makeStr() const override ;
    std::string makeTableHead() const override;

    std::string className() const override;

    void writeBin(BinaryFile& bin) override ;
    bool readBin(BinaryFile& bin) override ;
};

