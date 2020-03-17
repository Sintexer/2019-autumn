#pragma once
#include "Asteroid.h"
class Comet :
	public Asteroid
{
protected:
	std::string tail_composition;
	double tail_length;
public:
	Comet() : Asteroid(), tail_composition("None"), tail_length(0){}
	Comet(const Comet& cmt) = default;
	Comet(double m, double v, double t, std::string me, std::string tc, double tl) :
		Asteroid(m, v, t, me), tail_composition(std::move(tc)), tail_length(tl){}
	~Comet() override  = default;

    void print() override;

    void input() override;

    friend std::istream& operator>> (std::istream& in, Comet& obj);
	friend std::ostream& operator<< (std::ostream& out, Comet& obj);

	Comet& operator=(const Comet& cmt);

    void setTailComposition(const std::string &tailComposition);
    void setTailLength(double tailLength);
    const std::string &getTailComposition() const;
    double getTailLength() const;

    bool operator==(const Comet &rhs) const;
    bool operator!=(const Comet &rhs) const;
	bool operator>(const Comet& rhs) const;
	bool operator<(const Comet& rhs) const;

    std::string makeStr() const override ;
    std::string makeTableHead() const override;

    std::string className() const override;
};

