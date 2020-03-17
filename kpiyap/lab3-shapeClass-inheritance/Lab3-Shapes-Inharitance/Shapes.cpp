#include <iostream>
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Cylinder.h"
#include "Sphere.h"


int main()
{
	Triangle t(2, 5);
	std::cout << t << "\nArea= " << t.area() << "\n" << std::endl;

	Rectangle r(3, 7);
	std::cout << r << "\nArea= " << r.area() << "\n" << std::endl;

	Circle ci(5);
	std::cout << ci << "\nArea= " << ci.area() << "\n" << std::endl;

	Cylinder cy(21, 8);
	std::cout << cy << "\nArea= " << cy.area() << "\nVolume= " << cy.volume() << "\n" << std::endl;

	Sphere s(95);
	std::cout << s << "\nArea= " << s.area() << "\nVolume= " << s.volume() << "\n" << std::endl;

	Shape* ptr1;
	ptr1 = new Triangle;
	std::cout << "\nInput Triangle's h and a: ";
	std::cin >> *ptr1;
	std::cout << *ptr1 << "\nArea= " << ptr1->area() << "\n" << std::endl;
	delete ptr1;

	Shape* ptr2;
	ptr2 = new Rectangle;
	std::cout << "\nInput Rectangle's h and a: ";
	std::cin >> *ptr2;
	std::cout << *ptr2 << "\nArea= " << ptr2->area() << "\n" << std::endl;
	delete ptr2;

	Shape* ptr3;
	ptr3 = new Circle;
	std::cout << "\nInput Circle's r: ";
	std::cin >> *ptr3;
	std::cout << *ptr3 << "\nArea= " << ptr3->area() << "\n" << std::endl;
	delete ptr3;

	Shape* ptr4;
	ptr4 = new Cylinder;
	std::cout << "\nInput Cylinder's h and r: ";
	std::cin >> *ptr4;
	std::cout << *ptr4  << "\nArea= " << ptr4->area();
	std::cout << "\nVolume= " << ((ThreeDShape*)ptr4)->volume() << "\n" << std::endl;
	delete ptr4;

	Shape* ptr5;
	ptr5 = new Sphere;
	std::cout << "\nInput Sphere's r: ";
	std::cin >> *ptr5;
	std::cout << *ptr5 << "\nArea= " << ptr5->area();
	std::cout << "\nVolume= " << ((ThreeDShape*)ptr5)->volume() << "\n" << std::endl;
	delete ptr5;

}