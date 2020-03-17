#pragma once
#include "pch.h"



class Exc {					//Родительский класс исключения
protected:
    std::string exception_def;			//Описание исключения
public:
    Exc():exception_def("None definition"){}
    explicit Exc(std::string exception_definition): exception_def(std::move(exception_definition)){}

    const string& getExcDef() const;	//Возвращает описание исключения
};

void unpackExc(std::ostream& out, Exc& error);		//Функция выводит информацию исключения на экран

class Exc_input:			//Исключение, вызванное пользательским вводом
        public Exc
{
protected:
    int Exc_code;		//Код ошибки ввода
public:
    Exc_input(): Exc(), Exc_code(0){}
    Exc_input(int code, std::string exception_definition):Exc(std::move(exception_definition)), Exc_code(code){}

    const int getExcCode();			//Возвращает код ошибки ввода
};

class Exc_input_range :		//Ошибка ввода в диапазоне чисел
        public Exc_input
{
protected:
    int left_bound, right_bound;	//Границы ввода числа, left_bound должна быть меньше right_bound
public:
    Exc_input_range() : Exc_input(), left_bound(0), right_bound(0){}
    Exc_input_range(int code, std::string exception_definition, int lft, int rht) :Exc_input(code, std::move(exception_definition)), left_bound(lft), right_bound(rht)
    {}

    const int getLeftBound();			//Возвращает левую границу диапазона
    const int getRightBound();				//Возвращает правую границу диапазона
};

class Exc_file :							//Исключение работы с файлом
        public Exc
{
protected:
    string path{};								//Путь файла, в работе с которым произошла ошибка
public:
    Exc_file() : Exc(){}
    Exc_file(string def, string file_path) : Exc(def), path(file_path){}

    const string getPath();							//Метод Возвращает путь к файлу
};


template<typename T>
void inputSafe(std::istream& in, T& num) {						//Функция безопасного ввода числа
    bool flag{ true };						//Устанавливается в false, если было вызвано исключение
    while (flag)						//Если не было вызвано исключение, то ввод завершается
    {
        try {
            flag = false;
            in >> num;
            if (!in.good() || in.peek() != '\n')	//Если установился флаг ошибки или поток не пуст
                throw Exc_input(1, "Ввод неккоректен");
        }
        catch (Exc_input& error)
        {
            flag = true;
            unpackExc(cerr, error);
            cout << "Введите число" << endl;
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
void inputSafe(std::istream& in, T& num, size_t range_left, size_t range_right) {	//Функция ввода числа в границах диапазона
    bool flag{ true };																//Устанавливается в false, если было вызвано исключение
    while (flag)
    {
        try {
            flag = false;			//Если не было вызвано исключение, то ввод завершается
            in >> num;
            if (!in.good() || in.peek() != '\n')			//Если установился флаг ошибки или поток не пуст
                throw Exc_input(2, "Ввод не является числом");
            if (!(num >= range_left && num <= range_right))				//Проверка на границы диапазона
                throw Exc_input_range(4, "Введенный элемент не входит в диапазон", range_left, range_right);

        }
        catch (Exc_input_range& error) {
            flag = true;
            unpackExc(std::cerr, error);
            cout << "Введите число между " << error.getLeftBound() << " и " << error.getRightBound() << endl;
            rewind(stdin);
            in.clear();
        }
        catch (Exc_input& error) {
            flag = true;
            unpackExc(std::cerr, error);
            cout << "Введите число: " << endl;
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


void safeStr(std::istream& in, std::string& str);	//Функция безопасного ввода строки

