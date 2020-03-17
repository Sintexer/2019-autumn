#pragma once

class Node	
{
public:
	int count;
	char ch;
	Node* left, * right;

	Node() :left(0), right(0), ch(0), count(0)
	{}

	Node(char c, int n) : count(n), ch(c), left(0), right(0)
	{}

	Node(Node* l, Node* r) : left(l), right(r), ch(0)
	{
		count = left->count + right->count;
	}
};

