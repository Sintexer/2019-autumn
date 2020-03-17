#pragma once
#include "Meteor.h"
class Bolid :
	public Meteor
{
protected:
	double sound_power;
public:
	Bolid() : Meteor(), sound_power(0){}
	Bolid(const Bolid& bl) = default;
	Bolid(double m, double v, double t, std::string me, double h, double d, double sp) :
		Meteor(m, v, t, me, h, d), sound_power(sp){}
	~Bolid() override = default;

    void print() override;

    void input() override;

    friend std::istream& operator>> (std::istream& in, Bolid& obj);
	friend std::ostream& operator<< (std::ostream& out, Bolid& obj);
    friend  std::ifstream& operator>> (std::ifstream& in, Bolid& obj);

    string getPath() override;
    string getPathBinary() override;

	Bolid& operator=(const Bolid& bld);

	bool operator==(const Bolid& rhs) const;
	bool operator!=(const Bolid& rhs) const;
	bool operator>(const Bolid& rhs) const;
	bool operator<(const Bolid& rhs) const;

    double getSoundPower() const;
    void setSoundPower(double soundPower);

    std::string makeStr() const override ;
    std::string makeTableHead() const override;

    std::string className() const override;

    void writeBin(BinaryFile& bin) override ;
    bool readBin(BinaryFile& bin) override ;
};

