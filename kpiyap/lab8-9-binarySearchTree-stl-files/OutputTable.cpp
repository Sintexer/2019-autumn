#include "OutputTable.h"

#include <utility>

OutputTable::OutputTable (std::string str): strokes(nullptr), str_num(0), col_num(2){
    head = '|'+str; //Making empty column in head for class name
    int pos=0;
    int prev=0;
    while((pos = head.find('|' , pos+1))!= std::string::npos)  //
        ++col_num;

    sizes = new size_t[size=col_num];
    sizes[0]=1;

    int i=1;
    pos=0;
    while((pos = head.find('|' , pos+1))!= std::string::npos)
    {
        sizes[i++]=head.substr(prev, pos-prev).length();
        prev=pos;
    }
    sizes[i++]=head.substr(prev, pos-prev).length();
}

OutputTable::~OutputTable() {
    delete[] strokes;
    delete[] sizes;
}

void OutputTable::setHead(std::string hd)
{
    head.clear();
    head = '|' + hd;
    col_num=2;
    size_t pos = 0, prev = 0;
    while((pos = head.find('|' , pos+1))!= std::string::npos)  //
        ++col_num;
    int i = 0;
    sizes = new size_t[col_num];
    while((pos = head.find('|' , pos+1))!= std::string::npos)
    {
        sizes[i++]=head.substr(prev, pos-prev).length();
        prev=pos;
    }
    sizes[i++]=head.substr(prev, pos-prev).length();
}

void OutputTable::add_str(std::string ns){
    ++str_num;
    if (size==0) size = str_num;
    if(str_num>size)
        size*=2;
    std::string* temp = nullptr;
    if(strokes) {
        temp = new std::string[str_num-1];
        for (size_t i = 0; i < str_num-1; ++i)
            temp[i] = strokes[i];
    }
    delete[] strokes;
    strokes = new std::string[size];
    size_t i = 0;
    if (temp)
        for (i = 0; i< str_num-1;++i)
            strokes[i]=temp[i];
    strokes[i]=std::move(ns);
    this->set_sizes();
}

std::ostream& operator<<(std::ostream& out, OutputTable& tb){
    tb.outHead(out);
    tb.outStrokes(out);
    return out << endl;
}

void OutputTable::set_sizes() {
    size_t pos = 0, prev = 0;
    for (size_t i = 0; i < str_num; ++i) {
        prev=0;
        for (size_t j = 0; j < col_num; ++j) {
            if ((pos = strokes[i].find('|', prev + 1)) == std::string::npos)
                pos = strokes[i].length();
            if (strokes[i].substr(prev, pos - prev).length() > sizes[j])
                sizes[j] = strokes[i].substr(prev, pos - prev).length();
            prev = pos;
        }
    }
}

void OutputTable::clear() {
    head.clear();
    delete[] strokes;
    strokes = nullptr;
    delete[] sizes;
    sizes = nullptr;
    str_num = 0;
    col_num = 2;
    size = 0;

}

void makeDelim(const size_t* sizes_arr, const int col_num, std::ostream& out){
    out << "+-";
    for ( size_t i = 0; i <col_num; ++i)
        out << std::string(sizes_arr[i] - 1, '-') + '+';
    out << endl;
}

void OutputTable::outHead(std::ostream& out){
    makeDelim(sizes, col_num, out); //+---+---+---+
    out << '|' ;
    size_t prev = 0, pos = 0, j = 0;
    out << std::string(sizes[0], ' ');
    for (j = 1; j < col_num; ++j) {
        if ((pos = head.find('|', prev + 1)) == std::string::npos)
            pos = strokes[j].length();
        out << std::setiosflags(std::ios::left) << setw(sizes[j])
            << head.substr(prev, pos - prev);
        prev = pos;
    }
    out << "|" << endl;
    makeDelim(sizes, col_num, out); //+---+---+---+
}

void OutputTable::outStrokes(std::ostream& out) {
    size_t prev = 0, pos = 0, j = 0;
    for (size_t i = 0; i < str_num; ++i) {
        prev = 0;
        out << "|";
        for (j = 0; j < col_num; ++j) {
            if((pos = strokes[i].find('|', prev + 1)) == std::string::npos)
                pos = strokes[i].length();
            out << std::setiosflags(std::ios::left) << setw(sizes[j])
                << strokes[i].substr(prev, pos - prev);
            prev = pos;
        }
        out << "|" << endl;
        makeDelim(sizes, col_num, out); //+---+---+---+
    }
}

