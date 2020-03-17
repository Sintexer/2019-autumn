#include "String.h"

void String::strcpy(const char* str2, int pos)
{
	if (pos >= size)
		return;
	int i{};
	while (pos<size && str2[i])
	{
		str[pos++] = str2[i++];
	}
}

char& String::operator[](int index) const
{
	return str[index];
}

char* String::operator()(int pos1, int pos2) const
{
	
	int size = pos2 - pos1 + 1;
	char* temp = new char[size + 1]{};
	if (pos1 > pos2 || pos1 > strlen(str) || pos2 > strlen(str))
		return temp;
	int i{}, j{};
	for (i = pos1, j = 0; i <= pos2; ++i, ++j)
	{
		temp[j] = str[i];
	}
	temp[size] = '\0';
	return temp;
}

bool String::operator>(const String& obj) const
{
	if (strlen(str) > strlen(obj.str))
		return true;
	if (strlen(str) == strlen(obj.str))
	{
		for (int i = 0; i < size; ++i)
		{
			if (str[i] > obj[i])
				return true;
			if (str[i] < obj[i])
				return false;
		}
	}
	return false;
}

bool String::operator<(const String& obj) const
{
	
	if (strlen(str) < strlen(obj.str))
		return true;
	if (strlen(str) == strlen(obj.str))
	{
		for (int i = 0; i < size; ++i)
		{
			if (str[i] < obj[i])
				return true;
			if (str[i] > obj[i])
				return false;
		}
	}
	return false;
}

bool String::operator==(const String& obj) const
{
	if (strlen(str) != strlen(obj.str))
		return false;
	for (int i = 0; i < size; ++i)
	{
		if (str[i] != obj[i])
			return false;
	}
	return true;
}

bool String::operator!=(const String& obj) const
{
	return !(*this == obj);
}

String& String::operator= (const String& obj)
{
	if (size != strlen(obj.str))
	{
		delete[] str;
		size = strlen(obj.str);
		str = new char[size + 1];
	}
	for (int i = 0; i < size; ++i)
	{
		str[i] = obj[i];
	}
	return* this;
}

String String::operator+ (const String& obj)
{
	String temp(strlen(str) + strlen(obj.str));
	temp.strcpy(str, 0);
	temp.strcpy(obj.str, strlen(str));
	temp.str[temp.size] = '\0';
	return temp;
}

String& String::operator++ ()
{
	for (int i = 0; i < strlen(str); ++i)
	{
		str[i] += 1;
	}
	return *this;
}

String& String::operator++ (int)
{
	String temp(*this);
	for (int i = 0; i < strlen(str); ++i)
	{
		str[i] += 1;
	}
	return temp;
}

String& String::operator-- ()
{
	for (int i = 0; i < strlen(str); ++i)
	{
		str[i] -= 1;
	}
	return *this;
}

String& String::operator-- (int)
{
	String temp(*this);
	for (int i = 0; i < strlen(str); ++i)
	{
		str[i] -= 1;
	}
	return temp;
}

void String::operator+= (const String& obj)
{
	*this = *this + obj;
}

std::ostream& operator <<(std::ostream& out, const String& obj)
{
	if (obj.size == 0)
	{
		out << "<Empty>";
	}
	for (int i = 0; i < obj.size; ++i)
	{
		out << obj[i];
	}
	return out;
}

std::istream& operator >>(std::istream& in, String& obj)
{
	int i = obj.size + 1;
	in.getline(obj.str, i);
	if (in.fail())
	{
		in.clear();
		in.ignore(32768, '\n');
	}
	return in;
}