#pragma once
#include <string>
#include <map>
#include <list>
#include <iostream>
#include "Node.h"

class countCompare
{
public:
	bool operator()(Node* l, Node* r) const
	{
		return l->count < r->count;
	}
};

void createList(std::string& str, std::list<Node*>& list);

void showMap(std::map<char, int>& map);

void createMap(std::string& str, std::map<char, int>& dictionary);