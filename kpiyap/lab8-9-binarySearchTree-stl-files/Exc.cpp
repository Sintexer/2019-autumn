#include "Exc.h"

void unpackExc(std::ostream& out, Exc& error){
	out << "|Вызвано исключение|\n" << error.getExcDef() << endl; //Вывод ошибки в переданный поток
}

const std::string& Exc::getExcDef() const {
    return exception_def; //Возвращает описание исключения
}


const int Exc_input::getExcCode() {
    return Exc_code;//Возвращает код исключения
}

void safeStr(std::istream& in, std::string& str)
{
	bool flag{true};//Устанавливается в false, если было вызвано исключение
	while (flag)
	{
		try {
			rewind(stdin); //Очистка потока от символов, которые могут помешать вводу строки в getline()
			getline(in, str); //Ввод строки из потока
			for (size_t i = 1; i < str.length(); ++i){
				if (!(str[i] >= 'A' && str[i] <= 'z'))
					throw(Exc_input(5, "Input str on English"));
			}
			flag = false; //Если не было вызвано исключение, то ввод завершается
		}
		catch (Exc_input& error) {
			flag = true; //Продолжить цикл ввода
			unpackExc(cout, error); //Вывод ошибки на экран
			cout << "Введите строку" << endl;
			rewind(stdin); //Очистка потока от пользовательского ввода
			in.clear(); //Сброс флагов потока
		}
		catch (...)
		{
			flag = true; //Продолжить цикл ввода
			cout << "Unexpected exception";
			rewind(stdin); //Очистка потока от пользовательского ввода
			in.clear(); //Сброс флагов потока
		}
	}
}

const int Exc_input_range::getLeftBound()
{
	return left_bound; //Возвращает левую границу диапазона
}

const int Exc_input_range::getRightBound()
{
	return right_bound; //Возвращает правую границу диапазона
}

const string Exc_file::getPath()
{
	return path; //Возвращает путь файла, в работе с которым произошла ошибка
}
