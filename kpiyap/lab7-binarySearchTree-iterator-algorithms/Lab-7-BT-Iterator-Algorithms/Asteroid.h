#pragma once
#include "SpaceObject.h"
class Asteroid :
	public SpaceObject {
protected:
    std::string metal;
public:
    Asteroid() : SpaceObject(), metal("None") {}
	Asteroid(const Asteroid& astr) : SpaceObject(static_cast<const SpaceObject&>(astr)), metal(astr.metal) {};
    Asteroid(double Mass, double Volume, double Temperature, std::string Metal)
        :SpaceObject(Mass, Volume, Temperature), metal(std::move(Metal)) {}
    ~Asteroid() override = default;

    void print() override;

    void input() override;

    friend std::istream &operator>>(std::istream &in, Asteroid &obj);
    friend std::ostream &operator<<(std::ostream &out, Asteroid &obj);

    Asteroid &operator=(const Asteroid &astr);

    bool operator==(const Asteroid& astr) const;
    bool operator!=(const Asteroid& astr) const;
	bool operator>(const Asteroid& astr) const;
	bool operator<(const Asteroid& astr) const;


    const std::string &getMetal() const;
    void setMetal(const std::string &metal);

    std::string makeStr() const override ;
    std::string makeTableHead() const override;

    std::string className() const override;

};
