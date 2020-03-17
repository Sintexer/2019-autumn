#pragma once
#include <iostream>
#include <iomanip>
#include <locale.h>
 
class Array
{
private:
	int size,
		*array;
public:

	Array():size(0), array(nullptr)
	{	
	
	}

	Array(const int sz): size(sz)
	{
		array = new int[size];
	}

	Array(const Array& obj)
	{
		delete[] array;
		size = obj.size;
		array = new int[size];
		for (int i = 0; i < size; i++)
		{
			array[i] = obj.array[i];
		}
		this->sort();
	}

	~Array()
	{
		delete[] array;
	}

	void sort();													//Shell-сортировка

	void printArray();												//Вывод

	void inputeArray();												//Ввод массива

	Array getIntersection(const Array& obj);						//Пересечение

	Array getMerger(Array& obj);									//Объединение
};