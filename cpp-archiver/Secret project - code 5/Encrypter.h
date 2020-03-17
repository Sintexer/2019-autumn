#pragma once
#include <map>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include "Node.h"
#include "Tree.h"
#include "Dictionary.h"
#include "Functions.h"

class Encrypter
{
private:
	std::string& string;
	Dictionary dict;
	Tree tree;
public:
	Encrypter(std::string& str);

	std::string putDictionary();

	void encodeStr(std::ofstream& outf);
};