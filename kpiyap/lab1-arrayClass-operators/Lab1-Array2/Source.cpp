#include "Array.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	int answer{ 1 };
	while (answer)
	{
		int size;

		std::cout << "¬ведите размер первого массива:" << std::endl;
		std::cin >> size;
		Array obj1(size);

		std::cout << "¬ведите первый массив" << std::endl;
		std::cin >> obj1;
		obj1.sort();
		

		std::cout << "¬ведите размер второго массива:" << std::endl;
		std::cin >> size;
		Array obj2(size);

		std::cout << "¬ведите второй массив" << std::endl;
		std::cin >> obj2;
		obj2.sort();

		system("cls");  //ќчистка окна консоли

		std::cout << "Array1: " << obj1 << std::endl;
		std::cout << "Array2: " <<obj2 << std::endl;

		Array temp;
		temp = obj1 / obj2;
		std::cout  << "Intersection: " << temp << std::endl;

		temp = obj1 + obj2;
		std::cout << "Merge: " << temp << std::endl;

		std::cout << std::endl << "Continue? 1/0" << std::endl;
		std::cin >> answer;
		system("cls");  //ќчистка окна консоли
	}
	return 0;
}