#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <utility>
#include <math.h>
#include <limits.h>
#include "Exc.h"
using std::cin;
using std::cout;
using std::endl;
using std::setw;

std::string d_to_str(double d);

class SpaceObject{
protected:
	double mass{};
	double volume{};
	double temp{};
public:
    SpaceObject() = default;
    SpaceObject(SpaceObject &so) = default;
    SpaceObject(double Mass, double Volume, double Temperature) : mass(Mass), volume(Volume), temp(Temperature) {}
    virtual ~SpaceObject() = default;

    virtual void print();
    virtual void input();

    friend std::istream &operator>>(std::istream &in, SpaceObject &so);
    friend std::ostream &operator<<(std::ostream &out, const SpaceObject &so);

    SpaceObject &operator=(const SpaceObject &so);

    void setMass(double mass);
    void setVolume(double volume);
    void setTemp(double temp);
    double getMass() const;
    double getVolume() const;
    double getTemp() const;

    bool operator==(const SpaceObject &rhs) const;
    bool operator!=(const SpaceObject &rhs) const;
	bool operator>(const SpaceObject& rhs) const;
	bool operator<(const SpaceObject& rhs) const;

    virtual std::string makeStr() const;
    virtual std::string makeTableHead() const;
    virtual std::string className() const;
};