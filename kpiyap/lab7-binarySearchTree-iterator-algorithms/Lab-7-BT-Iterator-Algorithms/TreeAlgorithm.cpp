#include "TreeAlgorithm.h"


bool Comparator::operator()(Asteroid& obj1, Asteroid& obj2)
{
	int counter{};
	if (params.find("Mass:") != params.end())
		if (obj1.getMass() == obj2.getMass())
			++counter;
	if (params.find("Volume:") != params.end())
		if (obj1.getVolume() == obj2.getVolume())
			++counter;
	if (params.find("Temperature:") != params.end())
		if (obj1.getTemp() == obj2.getTemp())
			++counter;
	if (params.find("Metal:") != params.end())
		if (obj1.getMetal() == obj2.getMetal())
			++counter;
	return counter == params.size();
}


bool Comparator::operator()(Meteor& obj1, Meteor& obj2)
{
	int counter{};
	if (params.find("Mass:") != params.end())
		if (obj1.getMass() == obj2.getMass())
			++counter;
	if (params.find("Volume:") != params.end())
		if (obj1.getVolume() == obj2.getVolume())
			++counter;
	if (params.find("Temperature:") != params.end())
		if (obj1.getTemp() == obj2.getTemp())
			++counter;
	if (params.find("Metal:") != params.end())
		if (obj1.getMetal() == obj2.getMetal())
			++counter;
	if (params.find("Height:") != params.end())
		if (obj1.getHeight() == obj2.getHeight())
			++counter;
	if (params.find("Distance:") != params.end())
		if (obj1.getDistance() == obj2.getDistance())
			++counter;
	return counter == params.size();
}

bool Comparator::operator()(Bolid& obj1, Bolid& obj2)
{
	int counter{};
	if (params.find("Mass:") != params.end())
		if (obj1.getMass() == obj2.getMass())
			++counter;
	if (params.find("Volume:") != params.end())
		if (obj1.getVolume() == obj2.getVolume())
			++counter;
	if (params.find("Temperature:") != params.end())
		if (obj1.getTemp() == obj2.getTemp())
			++counter;
	if (params.find("Metal:") != params.end())
		if (obj1.getMetal() == obj2.getMetal())
			++counter;
	if (params.find("Height:") != params.end())
		if (obj1.getHeight() == obj2.getHeight())
			++counter;
	if (params.find("Distance:") != params.end())
		if (obj1.getDistance() == obj2.getDistance())
			++counter;
	if (params.find("Sound pw:") != params.end())
		if (obj1.getSoundPower() == obj2.getSoundPower())
			++counter;
	return counter == params.size();
}

bool Comparator::operator()(Comet& obj1, Comet& obj2)
{
	int counter{};
	if (params.find("Mass:") != params.end())
		if (obj1.getMass() == obj2.getMass())
			++counter;
	if (params.find("Volume:") != params.end())
		if (obj1.getVolume() == obj2.getVolume())
			++counter;
	if (params.find("Temperature:") != params.end())
		if (obj1.getTemp() == obj2.getTemp())
			++counter;
	if (params.find("Metal:") != params.end())
		if (obj1.getMetal() == obj2.getMetal())
			++counter;
	if (params.find("Tail comp. :") != params.end())
		if (obj1.getTailComposition() == obj2.getTailComposition())
			++counter;
	if (params.find("Tail len. :") != params.end())
		if (obj1.getTailLength() == obj2.getTailLength())
			++counter;
	return counter == params.size();
}

bool Comparator::operator()(Planet& obj1, Planet& obj2)
{//Rot. speed:|G:|Day last:|Satelites:|Name:
	int counter{};
	if (params.find("Mass:") != params.end())
		if (obj1.getMass() == obj2.getMass())
			++counter;
	if (params.find("Volume:") != params.end())
		if (obj1.getVolume() == obj2.getVolume())
			++counter;
	if (params.find("Temp:") != params.end())
		if (obj1.getTemp() == obj2.getTemp())
			++counter;
	if (params.find("Rot. speed:") != params.end())
		if (obj1.getRotationSpeed() == obj2.getRotationSpeed())
			++counter;
	if (params.find("G:") != params.end())
		if (obj1.getG() == obj2.getG())
			++counter;
	if (params.find("Day last:") != params.end())
		if (obj1.getDayLength() == obj2.getDayLength())
			++counter;
	if (params.find("Satelites:") != params.end())
		if (obj1.getNumberOfSatelites() == obj2.getNumberOfSatelites())
			++counter;
	if (params.find("Name:") != params.end())
		if (obj1.getPlanetName() == obj2.getPlanetName())
			++counter;
	return counter == params.size();
}

bool Comparator::operator()(BlackHole& obj1, BlackHole& obj2)
{//"Volume:|Temperature:|Type:
	int counter{};
	if (params.find("Volume:") != params.end())
		if (obj1.getVolume() == obj2.getVolume())
			++counter;
	if (params.find("Temp:") != params.end())
		if (obj1.getTemp() == obj2.getTemp())
			++counter;
	if (params.find("Type:") != params.end())
		if (obj1.getType() == obj2.getType())
			++counter;
	return counter == params.size();
}

bool Comparator::operator()(Star& obj1, Star& obj2)
{//|Luminosity:|Age:|Colour:
	int counter{};
	if (params.find("Mass:") != params.end())
		if (obj1.getMass() == obj2.getMass())
			++counter;
	if (params.find("Volume:") != params.end())
		if (obj1.getVolume() == obj2.getVolume())
			++counter;
	if (params.find("Temperature:") != params.end())
		if (obj1.getTemp() == obj2.getTemp())
			++counter;
	if (params.find("Luminosity:") != params.end())
		if (obj1.getLuminosity() == obj2.getLuminosity())
			++counter;
	if (params.find("Age:") != params.end())
		if (obj1.getAge() == obj2.getAge())
			++counter;
	if (params.find("Colour:") != params.end())
		if (obj1.getColour() == obj2.getColour())
			++counter;
	return counter == params.size();
}

bool Comparator::operator()(Sun& obj1, Sun& obj2)
{//System
	int counter{};
	if (params.find("Mass:") != params.end())
		if (obj1.getMass() == obj2.getMass())
			++counter;
	if (params.find("Volume:") != params.end())
		if (obj1.getVolume() == obj2.getVolume())
			++counter;
	if (params.find("Temperature:") != params.end())
		if (obj1.getTemp() == obj2.getTemp())
			++counter;
	if (params.find("Luminosity:") != params.end())
		if (obj1.getLuminosity() == obj2.getLuminosity())
			++counter;
	if (params.find("Age:") != params.end())
		if (obj1.getAge() == obj2.getAge())
			++counter;
	if (params.find("Colour:") != params.end())
		if (obj1.getColour() == obj2.getColour())
			++counter;
	if (params.find("System:") != params.end())
		if (obj1.getSystemName() == obj2.getSystemName())
			++counter;
	return counter == params.size();
}

std::set<std::string> getCompareParams(SpaceObject& obj) {
	std::set<std::string> temp{};
	std::string table_head = obj.makeTableHead();
	int pos = 0;
	int prev = 0;
	while ((pos = table_head.find('|', prev + 1)) != std::string::npos) {
		temp.insert(table_head.substr(prev, pos - prev));
		prev = pos + 1;
	}
	temp.insert(table_head.substr(prev, table_head.length()));
	std::set<std::string> params{};
	int answer{};
	do {
		cout << "Add compare argument: \n"
			<< " 1: Add all" << endl;
		int counter = 2;
		for (std::set<std::string>::iterator it = temp.begin(); it != temp.end(); ++it, ++counter)
		{
			cout << " " << counter << ": " << *it << endl;
		}
		cout << " 0: end" << endl;
		inputSafe(cin, answer, 0, temp.size() + 2);
		if (answer == 0)
			break;
		if (answer == 1) {
			params = temp;
			break;
		}
		std::set<std::string>::iterator it = temp.begin();
		for (int i = answer - 2; i > 0; --i, ++it);
		if (params.find(*it) == params.end())
			params.insert(*it);	
		else {
			cout << "This argument is already choosen\nDo you want to remove this argument? 1/0" << endl;
			int ans{};
			inputSafe(cin, ans, 0, 1);
			if (ans)
				params.erase(*it);
		}
	} while (answer);

	if (params.find("Mass:") != params.end()) {
		double tempik;
		cout << "Input mass for compare" << endl;
		inputSafe(cin,tempik);
		obj.setMass(tempik);
	}
	if (params.find("Volume:") != params.end()) {
		double tempik;
		cout << "Input volume for compare" << endl;
		inputSafe(cin, tempik);
		obj.setVolume(tempik);
	}
	if (params.find("Temperature:") != params.end()) {
		double tempik;
		cout << "Input temperature for compare" << endl;
		inputSafe(cin, tempik);
		obj.setTemp(tempik);
	}
	if (params.find("Metal:") != params.end()) {
		std::string tempik;
		cout << "Input metal for compare" << endl;
		safeStr(cin, tempik);
		dynamic_cast<Asteroid&>(obj).setMetal(tempik);
	}
	if (params.find("Height:") != params.end()) {
		double tempik;
		cout << "Input height for compare" << endl;
		inputSafe(cin, tempik);
		dynamic_cast<Meteor&>(obj).setHeight(tempik);
	}
	if (params.find("Distance:") != params.end()) {
		double tempik;
		cout << "Input distance for compare" << endl;
		inputSafe(cin, tempik);
		dynamic_cast<Meteor&>(obj).setDistance(tempik);
	}
	if (params.find("Sound pw:") != params.end()) {
		double tempik;
		cout << "Input sound power for compare" << endl;
		inputSafe(cin, tempik);
		dynamic_cast<Bolid&>(obj).setSoundPower(tempik);
	}
	if (params.find("Tail comp. ") != params.end()) {
		std::string tempik;
		cout << "Input tail composition for compare" << endl;
		safeStr(cin, tempik);
		dynamic_cast<Comet&>(obj).setTailComposition(tempik);
	}
	if (params.find("Tail len. ") != params.end()) {
		double tempik;
		cout << "Input tail length for compare" << endl;
		inputSafe(cin, tempik);
		dynamic_cast<Comet&>(obj).setTailLength(tempik);
	}
	if (params.find("Name:") != params.end()) {
		std::string tempik;
		cout << "Input Planet name for compare" << endl;
		safeStr(cin, tempik);
		dynamic_cast<Planet&>(obj).setPlanetName(tempik);
	}
	if (params.find("Day last:") != params.end()) {
		double tempik;
		cout << "Input day length for compare" << endl;
		inputSafe(cin, tempik);
		dynamic_cast<Planet&>(obj).setDayLength(tempik);
	}
	if (params.find("G:") != params.end()) {
		double tempik;
		cout << "Input G for compare" << endl;
		inputSafe(cin, tempik);
		dynamic_cast<Planet&>(obj).setG(tempik);
	}
	if (params.find("Satelites:") != params.end()) {
		double tempik;
		cout << "Input number of satelites for compare" << endl;
		inputSafe(cin, tempik);
		dynamic_cast<Planet&>(obj).setNumberOfSatelites(tempik);
	}
	if (params.find("Rot. speed:") != params.end()) {
		double tempik;
		cout << "Input rotation speed for compare" << endl;
		inputSafe(cin, tempik);
		dynamic_cast<Planet&>(obj).setRotationSpeed(tempik);
	}
	if (params.find("Type:") != params.end()) {
		std::string tempik;
		cout << "Input black hole type for compare" << endl;
		inputSafe(cin, tempik);
		dynamic_cast<BlackHole&>(obj).setType(tempik);
	}
	if (params.find("Luminosity:") != params.end()) {
		double tempik;
		cout << "Input luminosity for compare" << endl;
		inputSafe(cin, tempik);
		dynamic_cast<Star&>(obj).setLuminosity(tempik);
	}
	if (params.find("Age:") != params.end()) {
		double tempik;
		cout << "Input age for compare" << endl;
		inputSafe(cin, tempik);
		dynamic_cast<Star&>(obj).setAge(tempik);
	}
	if (params.find("Colour:") != params.end()) {
		std::string tempik;
		cout << "Input colour for compare" << endl;
		inputSafe(cin, tempik);
		dynamic_cast<Star&>(obj).setColour(tempik);
	}
	if (params.find("System:") != params.end()) {
		std::string tempik;
		cout << "Input system for compare" << endl;
		inputSafe(cin, tempik);
		dynamic_cast<Sun&>(obj).setSystemName(tempik);
	}
	return params;
}
