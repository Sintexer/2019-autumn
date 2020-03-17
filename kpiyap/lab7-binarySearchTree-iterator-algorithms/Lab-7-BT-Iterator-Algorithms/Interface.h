#pragma once

#include <iostream>
#include <set>
#include <list>
#include "Tree.h"
#include "Exc.h"
#include "Bolid.h"
#include "Comet.h"
#include "BlackHole.h"
#include "Planet.h"
#include "Sun.h"
#include "pch.h"
#include "TreeAlgorithm.h"

template <typename T>
class Interface {
public:
    void launch();
    bool work();
};

template <typename T>
void Interface<T>::launch() {

    int answer{};
    do {
		system("cls");
        cout << "Choose Tree Node type: \n"
			 << " 1: Asteroid\n"
			 << " 2: Meteor\n"
			 << " 3: Bolid\n"
			 << " 4: Comet\n"
			 << " 5: Black Hole\n"
			 << " 6: Planet\n"
			 << " 7: Star\n"
			 << " 8: Sun\n"
             << "\n 0: Exit program" << endl;
		inputSafe(cin, answer);
        switch (answer) {
			case 1: {
				Interface<Asteroid> temp;
				if (!temp.work())
					return;
				break;
			}
			case 2: {
				Interface<Meteor> temp;
				if (!temp.work())
					return;
				break;
			}
			case 3: {
				Interface<Bolid> temp;
				if (!temp.work())
					return;
				break;
			}
			case 4: {	
				Interface<Comet> temp;
				if (!temp.work())
					return;
				break;
			}
			case 5: {
				Interface<BlackHole> temp;
				if (!temp.work())
					return;
				break;
			}
			case 6: {
				Interface<Planet> temp;
				if (!temp.work())
					return;
				break;
			}
			case 7: {
				Interface<Star> temp;
				if (!temp.work())
					return;
				break;
			}
			case 8: {
				Interface<Sun> temp;
				if (!temp.work())
					return;
				break;
			}
            case 0: {
                return;
            }
            default: {
                cout << "\nIncorrect answer, choose option from list" << endl;
				system("pause");
                break;
            }
        }
    }while (answer);
}

template<typename T>
bool Interface<T>::work()
{
    Tree<T> tree;
	OutputTable tab;
    int answer;

    do {
		system("cls");
		cout << "Menu: \n"
			<< "1: Add item\n"
			<< "2: Pop item\n"
			<< "3: Show tree\n"
			<< "4: Tree size\n"
			<< "5: Find all similar to (input)\n"\
			<< "6: Lower bound\n"
			<< "7: Delete tree\n"
             << "\n8: Exit to MainMenu\n"
             << "0: Exit program"<< endl;
        inputSafe(cin, answer);
		bool flag{};
        switch (answer) {
            case 1: {
                T temp;
                cout << "Input item: " << endl;
				inputSafe(cin, temp);
				tree.insert(temp);
                break;
            }
            case 2: {
                T temp;
                cout << "Input item for pop: " << endl;
				inputSafe(cin, temp);
				tree.pop(temp);
                break;
            }
            case 3: {
				system("cls");
				createTable(tree.begin(), tree.end());
				system("pause");
                break;
            }
			case 4: {
				system("cls");
				cout << "Tree size = " << size(tree.begin(), tree.end()) << endl;
				system("pause");
				break;
			}
			case 5: {
				T temp;
				std::list<T> ans;
				ans = search_all(tree, temp);
				tab.clear();
				if (ans.size()) {
					tab.setHead(static_cast<SpaceObject&>(*(ans.begin())).makeTableHead());

					for (typename std::list<T>::iterator it = ans.begin(); it != ans.end(); ++it)
						tab.add_str((*it).makeStr());
				}
				cout << tab;
				system("pause");
				system("cls");
				break;
			}
			case 6: {
				T obj;
				tab.clear();
				cout << "Input element for lower bound" << endl;
				cin >> obj;
				typename Tree<T>::iterator temp = lower_bound(tree, obj);
				//
				tab.setHead(static_cast<SpaceObject&>(obj).makeTableHead());
				tab.add_str(static_cast<SpaceObject&>(*temp).makeStr());
				cout << tab;
				system("pause");
				system("cls");
				//
				break;
			}
            case 7: {
                tree.destroyTree(tree.getRoot());
                break;
            }
			
            case 8: {
                return true;
            }
            case 0: {
                return false;
            }
            default: {
				cout << "\nIncorrect answer, choose option from list" << endl;
				system("pause");
                break;
            }

        }
    }while(answer);
    return true;
}


