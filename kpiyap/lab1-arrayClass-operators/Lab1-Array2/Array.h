#pragma once
#include <iostream>
#include <iomanip>
#include <locale.h>

class Array
{
private:

	int size,
		* array;

public:

	Array();

	Array(const int sz);

	Array(const Array& obj);

	~Array();

	void sort();													//Shell-сортировка

	int& operator[](const int index);

	Array operator/(const Array& obj);								//Пересечение

	Array& operator=(Array obj);									//Присвоение

	Array operator+(const Array& obj);								//Слияние

	friend std::ostream& operator<<(std::ostream& out, const Array& obj);

	friend std::istream& operator>>(std::istream& in, const Array& obj);
};