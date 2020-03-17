//
// Created by Z97-61d on 30.10.2019.
//
#include "SpaceObject.h"
#include <cstring>
#include <utility>
#pragma once

class OutputTable {
private:
    std::string head;
    std::string* strokes;
    size_t* sizes;
    int str_num;
    int col_num;
    size_t size;

    void set_sizes(); //set size_t size for each column according to the longest str in column
public:
    explicit OutputTable (std::string str);
    explicit OutputTable (SpaceObject* obj): OutputTable(obj->makeStr()) {}
    ~OutputTable();

    void add_str(std::string ns);
    void setHead(std::string hd);

    friend std::ostream& operator<<(std::ostream& out, OutputTable& tb);

    void outHead(std::ostream& out);
    void outStrokes(std::ostream& out);
    void clear();
};

void makeDelim(const size_t* sizes_arr, int col_num, std::ostream& out);