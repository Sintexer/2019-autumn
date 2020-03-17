#include "Exc.h"
#include "pch.h"


void unpackExc(std::ostream& out, Exc& error){
	out << "|Raised exception|\n" << error.getExcDef() << endl;
}

const std::string &Exc::getExcDef() const {
    return exception_def;
}

void Exc::setExcDef(const std::string &exceptionDef) {
    exception_def = exceptionDef;
}

const int Exc_input::getExcCode() {
    return Exc_code;
}

void safeStr(std::istream& in, std::string& str)
{
	bool flag{ 1 };

	while (flag)
	{
		try {
			flag = false;
			rewind(stdin);
			getline(in, str);
			if ((str[0] >= '0' && str[0] <= '9') || !in.good())
				throw Exc_input(3, "Inputed str must be a words, shouldn't start with num");
			for (size_t i = 1; i < str.length(); ++i)
			{
				if (!isalpha(str[i]) && !(str[i] >= '0' && str[i] <= '9'))
					throw(Exc_input(5, "Inputed str must be written on English"));
			}
			flag = false;
		}
		catch (Exc_input& error) {
			flag = true;
			unpackExc(cout, error);
			cout << "Input a word: " << endl;
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