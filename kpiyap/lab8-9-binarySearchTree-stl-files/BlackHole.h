#pragma once
#include "SpaceObject.h"
class BlackHole :
	public SpaceObject
{
protected:
	std::string type;
	//type : Stellar, supermassive, intermediate
public:
	BlackHole() : SpaceObject(), type(""){}
	BlackHole(const BlackHole& bh) = default;
	BlackHole(double volume, double temp, std::string Type) : SpaceObject(1, volume, temp), type(std::move(Type)){}
	~BlackHole() override = default;

    void print() override;

    void input() override;

    friend std::istream& operator>> (std::istream& in, BlackHole& obj);
	friend std::ostream& operator<< (std::ostream& out, BlackHole& obj);
    friend std::ifstream& operator>>(std::ifstream &in, BlackHole &obj);

    string getPath() override;
    string getPathBinary() override ;

	BlackHole& operator= (const BlackHole& bh);

    const std::string &getType() const;
    void setType(const std::string &type);

    bool operator==(const BlackHole &rhs) const;
    bool operator!=(const BlackHole &rhs) const;
	bool operator>(const BlackHole& rhs) const;
	bool operator<(const BlackHole& rhs) const;

    std::string makeStr() const override ;
    std::string makeTableHead() const override;

    std::string className() const override;

    void writeBin(BinaryFile& bin) override ;
    bool readBin(BinaryFile& bin) override ;
};

