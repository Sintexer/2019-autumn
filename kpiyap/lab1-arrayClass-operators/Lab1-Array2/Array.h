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

	void sort();													//Shell-����������

	int& operator[](const int index);

	Array operator/(const Array& obj);								//�����������

	Array& operator=(Array obj);									//����������

	Array operator+(const Array& obj);								//�������

	friend std::ostream& operator<<(std::ostream& out, const Array& obj);

	friend std::istream& operator>>(std::istream& in, const Array& obj);
};