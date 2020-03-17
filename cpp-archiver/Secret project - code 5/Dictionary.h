#pragma once
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iostream>
#include "Node.h"

class Dictionary
{
private:
	std::map<char, std::vector<bool> > char_codes;
public:

	void makeDictionary(Node* ptr, std::vector<bool>& buffer);

	void showDictionary();

	std::string putDictionary();
};