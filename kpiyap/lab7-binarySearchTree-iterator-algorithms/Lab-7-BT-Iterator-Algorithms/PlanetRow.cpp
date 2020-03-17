#include "PlanetRow.h"

Planet& PlanetRow::operator[](size_t index){
    return Row[index];
}

std::ostream &operator<<(std::ostream &out, const PlanetRow &row) {
    return out << row.makeTableHead() << endl << row.makeStr();
}

void PlanetRow::add_planet(Planet& pl){
	PlanetRow temp(*this);
    ++quantity;
    if(quantity>size)
        size=quantity*2;
    delete[] Row;
    Row = new Planet[size]{};
    int i;
    for (i = 0 ; i< temp.quantity; i++)
        Row[i]=temp.Row[i];
    Row[i]=pl;
}

Planet PlanetRow::pop_planet(){
    --quantity;
    Planet temp(Row[quantity]);
    Row[quantity] = Planet();
    return temp;
}

Planet *PlanetRow::getRow() const {
    return Row;
}

void PlanetRow::setRow(Planet *row) {
    delete[] Row;
    Row = row;
}

int PlanetRow::getQuantity() const {
    return quantity;
}

void PlanetRow::setQuantity(int quantity) {
    PlanetRow::quantity = quantity;
}

int PlanetRow::getSize() const {
    return size;
}

void PlanetRow::setSize(size_t size) {
    PlanetRow::size = size;
}

bool PlanetRow::operator==(const PlanetRow &rhs) const {
    if (this->quantity==rhs.quantity)
        for ( int i = 0; i<quantity; ++i) if (Row[i]!=rhs.Row[i]) return false;
    return true;
}

bool PlanetRow::operator!=(const PlanetRow &rhs) const {
    return !(rhs == *this);
}

std::string PlanetRow::makeStr() const
{
    std::string s;
    for (size_t i = 0; i < quantity; ++i)
    {
        s+=Row[i].makeStr()+'\n';
    }
    return s;
}

std::string PlanetRow::makeTableHead() const{
    return Row->makeTableHead();
}

void PlanetRow::print() {
    cout << *this;
}
