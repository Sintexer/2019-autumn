#include "Array.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	
	int answer = 1;

	while (answer)
	{
			int size;
			std::cout << "������� ������ ������� �������:" << std::endl;
			std::cin >> size;
			Array obj1(size);
			std::cout << "������� ������ ������" << std::endl;
			obj1.inputeArray();
			obj1.sort();

			std::cout << "������� ������ ������� �������:" << std::endl;
			std::cin >> size;
			Array obj2(size);
			std::cout << "������� ������ ������" << std::endl;
			obj2.inputeArray();
			obj2.sort();
			
			system("cls");  //������� ���� �������

			std::cout << "Array1: ";
			obj1.printArray();
			std::cout << "Array2: ";
			obj2.printArray();
			Array temp1(obj1.getIntersection(obj2));
			std::cout << "�����������: ";
			temp1.printArray();
			Array temp2(obj1.getMerger(obj2));
			std::cout << "�������: ";
			temp2.printArray();
			std::cout << "Continue? 1/0" << std::endl;
			std::cin >> answer;
			system("cls");  //������� ���� �������
	}
	
	return 0;
}