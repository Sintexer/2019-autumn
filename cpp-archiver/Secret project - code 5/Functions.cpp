#include "Functions.h"	

void createList(std::string& str, std::list<Node*>& list)
{
	std::map<char, int> dictionary;
	createMap(str, dictionary);
	//showMap(dictionary);///////////////////////////////////

	std::map<char, int>::iterator itr = dictionary.begin();
	for (; itr != dictionary.end(); itr++)
	{
		Node* p = new Node(itr->first, itr->second);
		list.push_front(p);
	}
}

void createMap(std::string& str, std::map<char, int>& dictionary)
{
	for (int i = 0; i < str.size(); i++)
		dictionary[str[i]]++;
}

void showMap(std::map<char, int>& map)
{
	std::map<char, int>::iterator itr = map.begin();
	for (; itr != map.end(); ++itr)
		std::cout << itr->first << ':' << itr->second << std::endl;
}