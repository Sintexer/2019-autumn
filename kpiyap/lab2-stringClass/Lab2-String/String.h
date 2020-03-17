#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <locale.h>
#include <string>

class String
{
private:
	int size;
	char* str;
public:

	String(int sz=0) : size(sz)
	{
		str = new char[size+1]{};
	}

	String(const String& obj)
	{
		size = obj.size;
		str = new char[size+1]{};
		for (int i = 0; i < size; ++i)
		{
			str[i] = obj[i];
		}
		str[size] = '\0';
	}

	~String()
	{
		delete str;
	}

	void strcpy(const char* str2, int pos);
	
	char& operator[](int index) const;

	char* operator()(int pos1, int pos2) const;

	bool operator>(const String& obj) const;

	bool operator<(const String& obj) const;

	bool operator==(const String& obj) const;

	bool operator!=(const String& obj) const;

	String& operator= (const String& obj);

	String operator+ (const String& obj);

	String& operator++ ();

	String& operator++ (int);

	String& operator-- ();

	String& operator-- (int);

	void operator+= (const String& obj);

	friend std::ostream& operator <<(std::ostream& out, const String& obj);

	friend std::istream& operator >>(std::istream& in, String& obj);
};