#pragma once

#include "pch.h"
#include <iostream>
#include <string>

//void input(std::istream& in, double& num, size_t left_diap=0, double right_diap=2*pow(10, 308));
//void input(std::istream& in, int& num, size_t left_diap=0, size_t right_diap=INT_MAX);


class Exc {
protected:
    std::string exception_def;
public:
    Exc():exception_def("None definition")
    {}
    explicit Exc(std::string exception_definition): exception_def(std::move(exception_definition))
    {}

    const std::string &getExcDef() const;

    void setExcDef(const std::string &exceptionDef);
};


class Exc_input:
        public Exc
{
protected:
    int Exc_code;
public:
    Exc_input(): Exc(), Exc_code(0)
    {}
    Exc_input(int code, std::string exception_definition):Exc(std::move(exception_definition)), Exc_code(code)
    {}

    const int getExcCode();
};

void unpackExc(std::ostream& out, Exc& error);

template<typename T>
void inputSafe(std::istream& in, T& num) {
	bool flag{ true };
	while (flag)
	{
		try {
			flag = false;
			in >> num;
			if (typeid(T)==typeid(int) || typeid(T)==typeid(double))
				if (!in.good() || in.peek() != '\n')
					throw Exc_input(1, "Inputed element is not correct");
		}
		catch (Exc_input& error)
		{
			flag = true;
			unpackExc(cout, error);
			cout << "Input " << typeid(T).name() << ": " << endl;
			rewind(stdin);
			in.clear();
		}
		catch (...)
		{
			flag = true;
			cout << "Unexpected exception";
			rewind(stdin);
			in.clear();
		}
	}
}

template<typename T>
void inputSafe(std::istream& in, T& num, double range_left, double range_right) {
	bool flag{ true };
	while (flag)
	{
		try {
			flag = false;
			in >> num;
			if (!in.good() || in.peek() != '\n')
				throw Exc_input(1, "Inputed element is not a num");
			if (!(num > range_left && num < range_right))
				throw Exc_input(4, "Inputed element is not in range");

		}
		catch (Exc_input& error) {
			flag = true;
			unpackExc(cout, error);
			cout << "Input a number: " << endl;
			rewind(stdin);
			in.clear();
		}
		catch (...) {
			flag = true;
			cout << "Unexpected exception";
			rewind(stdin);
			in.clear();
		}
	}
}


void safeStr(std::istream& in, std::string& str);
