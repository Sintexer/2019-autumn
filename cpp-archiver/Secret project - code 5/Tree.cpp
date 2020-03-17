#include <iostream>
#include <vector>
#include <list>
#include "Tree.h"
#include "Functions.h"

void Tree::show(Node* p, int level)
{
	if (p)
	{
		show(p->left, level + 1);
		for (int i = 0; i < level; i++) std::cout << "   ";
		if (p->ch == 0) std::cout << p->count << std::endl;
		std::cout << p->ch << std::endl;
		show(p->right, level + 1);
	}
}

void Tree::createTree(std::list<Node*>& list)
{
	while (list.size() != 1)
	{
		list.sort(countCompare());
		Node* SonL = list.front();
		list.pop_front();
		Node* SonR = list.front();
		list.pop_front();
		Node* parent = new Node(SonL, SonR);
		list.push_back(parent);
	}
	root = list.front();
}