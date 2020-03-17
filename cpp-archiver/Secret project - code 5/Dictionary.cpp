#include "Dictionary.h"

void Dictionary::makeDictionary(Node* ptr, std::vector<bool>& buffer)
{
	if (ptr)
	{
		buffer.push_back(1);
		makeDictionary(ptr->left, buffer);

		if (ptr->ch) 
			char_codes[(ptr->ch)] = buffer;

		buffer.push_back(0);
		makeDictionary(ptr->right, buffer);
	}
	if (buffer.size() > 0) 
		buffer.pop_back();
}

void Dictionary::showDictionary()
{
	std::map<char, std::vector<bool> >::iterator itr = char_codes.begin();
	for (; itr != char_codes.end(); itr++)
	{
		std::cout << itr->first << " - ";
		std::vector<bool>::iterator i = itr->second.begin();
		for (; i != itr->second.end(); i++)
			std::cout << (*i ? "1" : "0");
		std::cout << std::endl;
	}
}

std::string Dictionary::putDictionary()
{
	std::string buffer;
	buffer.resize(1200);
	std::string::iterator bitr = buffer.begin();
	std::map<char, std::vector<bool> >::iterator itr = char_codes.begin();
	char chr{}, temp{};

	for (; itr != char_codes.end(); itr++)
	{
		*bitr = itr->first;
		bitr++;
		*bitr = itr->second.size();
		bitr++;
		int j{};
		std::vector<bool>::iterator i = itr->second.begin();
		for (; i != itr->second.end(); i++)
		{
			if (j != 8)
			{
				chr <<= 1;
				if (*i)
				{
					chr |= 1;
				}
				else
				{
					chr |= 0;
				}
				j++;
			}
			else
			{
				*bitr = chr;
				chr = 0;
				bitr++;
				j = 0;
			}
		}
		*bitr = chr;
		chr = 0;
		bitr++;
		j = 0;
	}

	return buffer;
}