#include <iostream>
#include "Encrypter.h"

Encrypter::Encrypter(std::string& str):string(str)
{
	std::list<Node*> list;
	createList(str, list);

	tree.createTree(list);
	//tree.show(tree.head(), 0);

	std::vector<bool> buffer;
	dict.makeDictionary(tree.head(), buffer);
	dict.showDictionary();
}

std::string Encrypter::putDictionary()
{
	/*std::string buffer;
	std::string::iterator bitr = buffer.begin();
	std::map<char, std::vector<bool> >::iterator itr = char_codes.begin();
	char chr, temp, tr;
	tr <<= 8;
	~tr;
	tr >>= 7;
	
	for (; itr != string.end(); itr++)
	{
		temp = *itr;
		chr <<= 8;
		for (int i = 0; i < 8; i++)
		{
			if (temp & tr)
				chr |= 1;
			else
				chr <<= 0;
			chr <<= 1;
			temp >>= 1;
		}
		*bitr = chr;
		bitr++;
	}
*/
	return dict.putDictionary();
}

void Encrypter::encodeStr(std::ofstream& outf)
{

}