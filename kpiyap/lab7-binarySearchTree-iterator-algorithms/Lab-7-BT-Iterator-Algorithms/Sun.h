#pragma once
#include "Star.h"
class Sun :
	public Star
{
protected:
	std::string system_name;
public:
	Sun() : Star(), system_name("None"){}
	Sun(const Sun& sn) = default;
	Sun(double m, double v, double t, double l, double a, std::string clr, std::string str) :
		Star(m, v, t, l, a, clr), system_name(str){}
	~Sun() override = default;

    void print() override;

    void input() override;

    friend std::istream& operator>> (std::istream& in, Sun& obj);
	friend std::ostream& operator<< (std::ostream& out, Sun& obj);

	Sun& operator=(const Sun& sn);

    const std::string &getSystemName() const;
    void setSystemName(const std::string &systemName);

    bool operator==(const Sun &rhs) const;
    bool operator!=(const Sun &rhs) const;
	bool operator>(const Sun& rhs) const;
	bool operator<(const Sun& rhs) const;

    std::string makeStr() const override ;
    std::string makeTableHead() const override;

    std::string className() const override;
};

