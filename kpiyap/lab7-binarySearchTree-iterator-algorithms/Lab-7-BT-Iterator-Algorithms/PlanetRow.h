#pragma once
#include "Planet.h"
#include <ostream>

class PlanetRow
{
protected:
    Planet* Row;
    int quantity;
    size_t size;
public:
    PlanetRow() : Row(nullptr), quantity(0), size(0){}
    PlanetRow(Planet* row, size_t sz): Row(row), size(sz), quantity (sz){}
    PlanetRow(const PlanetRow& row)
    {
		size = row.quantity;
		quantity = row.quantity;
		Row = new Planet[size];
		int counter = 0;
		for (int i = 0; i < quantity; ++i)
			Row[i] = row.Row[i];
    }
    explicit PlanetRow(Planet& pl):quantity(1), size(1)
    {
        Row = new Planet[size];
        Row[0]=(pl);
    }
    virtual ~PlanetRow()
    {
       delete[] Row;
    }

    virtual Planet& operator[](size_t index);
    friend std::ostream &operator<<(std::ostream &out, const PlanetRow &row);

    void print();

    void add_planet(Planet& pl);
    Planet pop_planet();

    Planet *getRow() const;
    void setRow(Planet *row);
    int getQuantity() const;
    void setQuantity(int quantity);
    int getSize() const;
    void setSize(size_t size);

    bool operator==(const PlanetRow &rhs) const;
    bool operator!=(const PlanetRow &rhs) const;

    std::string makeStr() const;
    std::string makeTableHead() const;
};

