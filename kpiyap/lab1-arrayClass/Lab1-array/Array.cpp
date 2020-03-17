#include "Array.h"
#include <time.h>

void Array::printArray()
{
	if (size == 0)
	{
		std::cout << "<Empty>";
	}
	for (int i = 0; i < size; ++i)
	{
		std::cout << std::setw(3) << array[i];
	}
	std::cout << std::endl;
}

void Array::sort()				//Сортировка алгоритмом Шелла
{
	int d = size;
	d = d / 2;
	while (d > 0)
	{
		for (int i = 0, j, temp; i < size - d; ++i)
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

void Array::inputeArray()					//Метод ввода значений массива
{
	for (int i = 0; i < size; ++i)
	{
		std::cin>>array[i];
	}
}

Array Array::getIntersection(const Array& obj)
{
	Array temp(size);
	int k{}, m{};

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < obj.size; ++j)
		{
			if (array[i] == obj.array[j])
			{
				for (m = 0; m < k; ++m)
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
	temp.size = k;
	return temp;
}

Array Array::getMerger(Array& obj)
{
	Array temp(size + obj.size);
	int k{};
	for (int i = 0, j; i < size; ++i)
	{
		for (j = 0; j < k; j++)
		{
			if (array[i] == temp.array[j])
				break;
		}
		if (j == k)
			temp.array[k++] = array[i];
	}
	for (int i = 0, j; i < obj.size; ++i)
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
	return temp;
}