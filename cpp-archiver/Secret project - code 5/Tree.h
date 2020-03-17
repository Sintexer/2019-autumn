#pragma once
#include "Node.h"
#include <map>
#include <string>

class Tree
{
private:
	Node* root;
	std::map <char, std::vector<bool> > dictionary;
public:

	Tree(): root(0)
	{}

	Tree(Node * ptr): root(ptr)
	{}

	Node* head()
	{
		return root;
	}

	~Tree()
	{
		delete root;
	}

	void show(Node* p, int level);

	void createTree(std::list<Node*>& list);
};