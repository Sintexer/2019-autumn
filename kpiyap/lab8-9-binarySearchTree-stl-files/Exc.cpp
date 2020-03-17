#include "Exc.h"

void unpackExc(std::ostream& out, Exc& error){
	out << "|������� ����������|\n" << error.getExcDef() << endl; //����� ������ � ���������� �����
}

const std::string& Exc::getExcDef() const {
    return exception_def; //���������� �������� ����������
}


const int Exc_input::getExcCode() {
    return Exc_code;//���������� ��� ����������
}

void safeStr(std::istream& in, std::string& str)
{
	bool flag{true};//��������������� � false, ���� ���� ������� ����������
	while (flag)
	{
		try {
			rewind(stdin); //������� ������ �� ��������, ������� ����� �������� ����� ������ � getline()
			getline(in, str); //���� ������ �� ������
			for (size_t i = 1; i < str.length(); ++i){
				if (!(str[i] >= 'A' && str[i] <= 'z'))
					throw(Exc_input(5, "Input str on English"));
			}
			flag = false; //���� �� ���� ������� ����������, �� ���� �����������
		}
		catch (Exc_input& error) {
			flag = true; //���������� ���� �����
			unpackExc(cout, error); //����� ������ �� �����
			cout << "������� ������" << endl;
			rewind(stdin); //������� ������ �� ����������������� �����
			in.clear(); //����� ������ ������
		}
		catch (...)
		{
			flag = true; //���������� ���� �����
			cout << "Unexpected exception";
			rewind(stdin); //������� ������ �� ����������������� �����
			in.clear(); //����� ������ ������
		}
	}
}

const int Exc_input_range::getLeftBound()
{
	return left_bound; //���������� ����� ������� ���������
}

const int Exc_input_range::getRightBound()
{
	return right_bound; //���������� ������ ������� ���������
}

const string Exc_file::getPath()
{
	return path; //���������� ���� �����, � ������ � ������� ��������� ������
}
