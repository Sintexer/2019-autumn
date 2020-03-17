#include "String.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	int size;
	std::cout << "¬ведите размер первой строки: " << std::endl;
	std::cin >> size;
	std::cin.ignore(32768, '\n');
	String obj1(size);
	std::cin >> obj1;
	
	std::cout << obj1 << std::endl;

	std::cout << "¬ведите размер второй строки: " << std::endl;
	std::cin >> size;
	std::cin.ignore(32768, '\n');
	String obj2(size);
	std::cin >> obj2;
	
	std::cout << obj2 << std::endl;

	if (obj1 > obj2)
		std::cout << "obj1>obj2" << std::endl;
	if (obj1 < obj2)
		std::cout << "obj1<obj2" << std::endl;
	if (obj1 == obj2)
		std::cout << "obj1==obj2" << std::endl;
	if (obj1 != obj2)
		std::cout << "obj1!=obj2" << std::endl;

	obj1 += obj2;
	std::cout << std::endl << obj1 << std::endl << obj2(1, 3) << std::endl << std::endl;
	obj2++;
	++obj2;
	std::cout << obj2 << std::endl;
	obj2--;
	std::cout << obj2 << std::endl;
	--obj2;
	std::cout << obj2 << std::endl;
}