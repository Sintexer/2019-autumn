#pragma once
#include <iostream>
#include <string>
#include <set>
#include <list>
#include "SpaceObject.h"
#include "Tree.h"
#include "Bolid.h"
#include "Comet.h"
#include "Planet.h"
#include "BlackHole.h"
#include "Sun.h"
#include "OutputTable.h"

// lower_bound
// upper_bound
// includes	
// min
// max

class Comparator {
private:
	std::set<std::string> params;
public:
	Comparator(std::set<std::string> comp_params) : params(comp_params) {};
	bool operator()(Asteroid& obj1, Asteroid& obj2);
	bool operator()(Meteor& obj1, Meteor& obj2);
	bool operator()(Bolid& obj1, Bolid& obj2);
	bool operator()(Comet& obj1, Comet& obj2);
	bool operator()(Planet& obj1, Planet& obj2);
	bool operator()(BlackHole& obj1, BlackHole& obj2);
	bool operator()(Star& obj1, Star& obj2);
	bool operator()(Sun& obj1, Sun& obj2);

};

template <typename T>
std::list<T> search_all(Tree<T>& tr, T& obj);

std::set<std::string> getCompareParams(SpaceObject& obj);


template<typename T>
std::list<T> search_all(Tree<T>& tr, T& obj)
{
	Comparator comp(getCompareParams(obj));
	std::list<T> ans;
	typename Tree<T>::iterator it;
	it= tr.begin();
	for (it; it != tr.end(); ++it) {
		if (comp(obj, *it)) {
			ans.push_back(*it);
		}
	}

	return ans;
}

template<typename Iter>
void createTable(Iter begin, Iter end) {
	OutputTable tab(static_cast<SpaceObject&>(*(begin)).makeTableHead());
	Iter it = begin;
	for (it; it != end; ++it)
		tab.add_str(static_cast<SpaceObject&>(*it).makeStr());
	if (tab.getSize())
		cout << tab;	
	else
		cout << "None" << endl;
}

template<typename Iter>
size_t size(Iter begin, Iter end)
{
	size_t ans{};
	Iter it = begin;
	for (it; it != end; ++it)
		++ans;
	return(ans);
}

template<typename T>
typename Tree<T>::iterator lower_bound(Tree<T>& tree,T& obj) {
	typename Tree<T>::iterator it = tree.begin();
	for (it;it!=tree.end();++it)
		if (*it > obj)
			break;
	return it;
}

template<typename T>
typename Tree<T>::iterator min(Tree<T>& tree)
{
	return tree.begin();
}

template<typename T>
typename Tree<T>::iterator max(Tree<T>& tree)
{
	return tree.rbegin();
}
