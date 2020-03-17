#pragma once
#include "SpaceObject.h"

class Planet :
	public SpaceObject
{
protected:
	double rotation_speed;
	double g;
	double	day_length;
	int number_of_satelites;
	std::string planet_name;
public:

	Planet(): SpaceObject(), rotation_speed(0), g(0), day_length(0), number_of_satelites(0), planet_name("No name"){}
	Planet(double m, double v, double t, double rs, double G, double dl, int nos, std::string name) :
		SpaceObject(m, v, t), rotation_speed(rs), g(G), day_length(dl), number_of_satelites(nos), planet_name(name){}
	Planet(const Planet& pl):
	    SpaceObject(pl.mass, pl.volume, pl.temp),
	    rotation_speed(pl.rotation_speed),
	    g(pl.g),
	    day_length(pl.day_length),
	    number_of_satelites(pl.number_of_satelites),
	    planet_name(pl.planet_name){}
	~Planet() override = default;

    void print() override;

    void input() override;

    friend std::istream& operator>> (std::istream& in, Planet& obj);
	friend std::ostream& operator<< (std::ostream& out, const Planet& obj);

    Planet& operator=(const Planet& pl);

    double getRotationSpeed() const;
    double getG() const;
    double getDayLength() const;
    int getNumberOfSatelites() const;
    const std::string &getPlanetName() const;

	void setRotationSpeed(double rs);
	void setG(double gt);
	void setDayLength(double dsl);
	void setNumberOfSatelites(int nos);
	void setPlanetName(std::string pn);

	bool operator==(const Planet& rhs) const;
	bool operator!=(const Planet& rhs) const;
	bool operator>(const Planet& rhs) const;
	bool operator<(const Planet& rhs) const;

    std::string makeStr() const override ;
    std::string makeTableHead() const override;

    std::string className() const override;
};

