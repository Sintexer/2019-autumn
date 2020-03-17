#include "Array.h"
#include <time.h>

Array::Array():size(0), array(nullptr)
{
}

Array::Array(const int sz = 0): size(sz)
{
	array = new int[size];
}

Array::Array(const Array& obj):size(obj.size)
{
	array = new int[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = obj.array[i];
	}
}

Array::~Array()
{
	delete[] array;
}

int& Array::operator[](const int index)
{
	return array[index];
}

Array Array::operator/(const Array& obj)
{
	int k{}, m{};
	Array temp(size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < obj.size; j++)
		{
			if (array[i] == obj.array[j])
			{
				for (m = 0; m < k; m++)
					if (array[i] == temp.array[m])
						break;
				if (m == k || k == 0)
				{
					temp.array[k++] = array[i];
					break;
				}
			}
		}
	}
	if (temp.size != k)
		temp.size = k;
	temp.sort();
	return temp;
}

Array& Array::operator=(Array obj)
{
	delete[] array;
	size = obj.size;
	array = new int[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = obj.array[i];
	}
	return *this;
}

Array Array::operator+(const Array& obj)
{
	Array temp(size + obj.size);
	int k{};
	for (int i = 0, j; i < size; i++)
	{
		for (j = 0; j < k; j++)
		{
			if (array[i] == temp.array[j])
				break;
		}
		if (j == k)
			temp.array[k++] = array[i];
	}
	for (int i = 0, j; i < obj.size; i++)
	{
		for (j = 0; j < k; j++)
		{
			if (obj.array[i] == temp.array[j])
				break;
		}
		if (j == k)
			temp.array[k++] = obj.array[i];
	}
	temp.size = k;
	temp.sort();
	return temp;
}

void Array::sort()				//Сортировка алгоритмом Шелла
{
	int d = size;
	d = d / 2;
	while (d > 0)
	{
		for (int i = 0, j, temp; i < size - d; i++)
		{
			j = i;
			while (j >= 0 && array[j] > array[j + d])
			{
				temp = array[j];
				array[j] = array[j + d];
				array[j + d] = temp;
				j--;
			}
		}
		d = d / 2;
	}
}

std::ostream& operator<<(std::ostream& out, const Array& obj)
{
	if (obj.size == 0)
		out << "<Empty>";
	for (int i = 0; i < obj.size; i++)
	{
		out << obj.array[i] << ' ';
	}
	return out;
}

std::istream& operator>>(std::istream& in, const Array& obj)
{
	for (int i = 0; i < obj.size; i++)
	{
		in >> obj.array[i];
	}
	return in;
}