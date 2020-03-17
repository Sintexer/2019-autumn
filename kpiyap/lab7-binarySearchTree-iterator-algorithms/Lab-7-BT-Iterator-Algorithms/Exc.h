#pragma once

#include "pch.h"
#include <iostream>
#include <string>

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
			if (typeid(T) == typeid(std::string)) {
				in.ignore(32768, '\n');
				if (in.gcount() > 1)
					throw Exc_input(3, "This string must be one word");
			}
		}
		catch (Exc_input& error)
		{
			flag = true;
			unpackExc(std::cerr, error);
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
				throw Exc_input(2, "Inputed element is not a num");
			if (!(num >= range_left && num <= range_right))
				throw Exc_input(4, "Inputed element is not in range");

		}
		catch (Exc_input& error) {
			flag = true;
			unpackExc(std::cerr, error);
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
