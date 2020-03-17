#ifndef LAB9_STL_FILE_H
#define LAB9_STL_FILE_H


#include "Exc.h"
#include <fstream>
#include "pch.h"

class File
{											// Класс файла, для настраиваемого создания и уничтожения объектов файловых потоков
protected:
    string file_path{};						//Путь файла
    std::ofstream fout{};					//Файловый выходной поток, привязвнный к file_path
    std::ifstream fin{};					//Файловый входной поток, привязвнный к file_path
public:
    File(string path): file_path(std::move(path)) //Конструктор через путь к файлу
    {}
    ~File(){								//Деструтор закрывает потоки
        fout.close();
        fin.close();
    }



    void flush();							//Внести изменения в файл из выходного потока, без закрытия потока
    bool in();								//Проверка, не закончился ли файл
    void close();							//Метод закрытия обоих потоков

    std::ifstream& getFin();				//Возаращает входной поток
    std::ofstream& getFout();				//Возвращает выходной поток

//    template<typename T>
//    void write(T obj, char delim = '\n');	//Метод записи объекта в файл
//
//    template<typename T>
//    bool readLine(T& obj);					//Метод считывает из файла строку и заносит ее в объект
//
//    template<typename T>
//    bool read(T& obj);						//Метод считывает из файла объект
};

class TextFile: public File{
public:
    TextFile() = default;
    TextFile(string path): File(path) {}
    bool open_out();						//Открыть выходной поток
    bool open_in();							//Открыть входной поток
    template <typename T>
    void write(T obj, char delim = '\n');

    template <typename T>
    bool read(T& obj);

    template <typename T>
    bool readLine(T& obj);
};

template<typename T>
void TextFile::write(T obj, char delim) {
    fout << obj << delim;
}

template<typename T>
bool TextFile::read(T& obj) {
    while (fin.peek() == '\n')				//Пропуск символов новой строки из буфера, которые могут остаться после ввода числа
        fin.get();
    fin.peek();
    if (fin.eof())							//Если конец файла
        return false;						//Возвращает false
    fin >> obj;								//Считывает объект из файла
    return true;							//Возвращает true
}

template<typename T>
bool TextFile::readLine(T &obj) {
    while (fin.peek() == '\n')				//Пропуск символов новой строки из буфера, которые могут остаться после ввода числа
        fin.get();
    fin.peek();
    if (fin.eof())							//Если конец файла
        return false;						//Возвращает false
    getline(fin, obj);						//Считывает строку из файла
    return true;							//Возвращает true
}

class BinaryFile : public File{
public:
    BinaryFile() = default;
    BinaryFile(string path): File(path) {}

    bool open_in();
    bool open_out();
    template <typename T>
    void write(T& obj);
    void writeLine(string& str);
    template <typename T>
    void read(T& obj);
    template <typename T>
    void readLine(T& obj, size_t size);

    };

template<typename T>
void BinaryFile::write(T& obj) {
    fout.write(reinterpret_cast<char*>(&obj), sizeof(obj));
}

template<typename T>
void BinaryFile::read(T &obj) {
    fin.read(reinterpret_cast<char*>(&obj), sizeof(obj));
}

template<typename T>
void BinaryFile::readLine(T &obj, size_t size) {
    char* temp = new char[size+1];
    fin.read(temp, size);
    temp[size] = '\0';
    obj = temp;
    delete[] temp;
}



#endif //LAB9_STL_FILE_H
