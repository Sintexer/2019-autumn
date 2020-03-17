//
// Created by Z97-61d on 19.12.2019.
//
#include "File.h"
#include "Exc.h"


bool File::in() {
    while (fin.peek() == '\n') //Пропуск символов новой строки из буфера, которые могут остаться после ввода числа
        fin.get();
    return !fin.eof(); //Возврат состояния конца потока
}

void File::close() {
    fin.close(); //Закрытие потоков ввода и вывода
    fout.close();
}

std::ifstream& File::getFin(){ //Возвращает входной поток
    return fin;
}

std::ofstream& File::getFout(){ //Возвращает выходной поток
    return fout;
}

bool TextFile::open_out(){ //Открывает файл для записи
    try {
        fout.open(file_path);
        if (!fout.is_open())//Если поток не открылся
            throw Exc_file("Невозможно открыть файл", file_path);
    }
    catch (Exc_file& err) {
        unpackExc(cerr, err); //Вывод ошибки на экран
        cerr << err.getPath() << endl;
        cerr << "Выход в меню" << endl;
        system("pause");
        return false;
    }
    catch (...) {
        cerr << "Unexpected exception" << endl;
    }
    return true;
}

bool TextFile::open_in(){ //Открывает файл для чтения
    try {
        fin.open(file_path);
        if (!fin.is_open())//Если поток не открылся
            throw Exc_file("Невозможно открыть файл", file_path);
    }
    catch (Exc_file& err) {
        unpackExc(cerr, err); //Вывод ошибки на экран
        cerr << err.getPath() << endl;
        cerr << "Выход в меню" << endl;
        system("pause");
        return false;
    }
    catch (...) {
        cerr << "Unexpected exception" << endl;
        return false;
    }
    return true;
}


inline void File::flush(){ //Выталкивает данные из потока в файл
    fout.flush();
}

bool BinaryFile::open_in() {
    try {
        fin.open(file_path, std::ios::binary);
        if (!fin.is_open())//Если поток не открылся
            throw Exc_file("Невозможно открыть файл", file_path);
    }
    catch (Exc_file& err) {
        unpackExc(cerr, err); //Вывод ошибки на экран
        cerr << err.getPath() << endl;
        cerr << "Выход в меню" << endl;
        system("pause");
        return false;
    }
    catch (...) {
        cerr << "Unexpected exception" << endl;
        return false;
    }
    return true;
}

bool BinaryFile::open_out() {
    try {
        fout.open(file_path, std::ios::binary);
        if (!fout.is_open())//Если поток не открылся
            throw Exc_file("Невозможно открыть файл", file_path);
    }
    catch (Exc_file& err) {
        unpackExc(cerr, err); //Вывод ошибки на экран
        cerr << err.getPath() << endl;
        cerr << "Выход в меню" << endl;
        system("pause");
        return false;
    }
    catch (...) {
        cerr << "Unexpected exception" << endl;
    }
    return true;
}

void BinaryFile::writeLine(string& str) {
    fout << str;
}