#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <utility>
#include <math.h>
#include <limits.h>
#include "Exc.h"
#include "pch.h"
#include "File.h"

std::string d_to_str(double d);

class SpaceObject{
protected:
	double mass{};
	double volume{};
	double temp{};
public:
    SpaceObject() = default;
	SpaceObject(const SpaceObject& so) : mass(so.mass), volume(so.volume), temp(so.temp) {};
    SpaceObject(double Mass, double Volume, double Temperature) : mass(Mass), volume(Volume), temp(Temperature) {}
    virtual ~SpaceObject() = default;

    virtual void print();
    virtual void input();

    friend std::istream &operator>>(std::istream &in, SpaceObject &so);
    friend std::ostream &operator<<(std::ostream &out, const SpaceObject &so);

    virtual string getPath();
    virtual string getPathBinary();

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

    virtual void writeBin(BinaryFile& bin);
    virtual bool readBin(BinaryFile& bin);
};