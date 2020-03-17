#include <map>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Node.h"
#include "Tree.h"
#include "Dictionary.h"
#include "Encrypter.h"
#include "Functions.h"


int main()
{
	
	std::ifstream inf("Source.txt");

	std::string str;
	getline(inf, str, '\0');
	/*int length; 
	inf.seekg(0, std::ios::end);
	length = inf.tellg();
	inf.seekg(0, std::ios::beg);
	std::string str;
	str.resize(length);*/

	/*inf.read(str, length);*/

	//while (inf)
	//{
	//	getline(inf, str);
	//}
	Encrypter code(str);


	std::ofstream outf("Encoded.txt");
	outf << code.putDictionary() << std::endl;
	return 0;
}
