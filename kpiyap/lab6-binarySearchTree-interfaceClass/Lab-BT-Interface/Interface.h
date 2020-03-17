#pragma once


#include <iostream>
#include "Tree.h"
#include "Exc.h"
#include "Bolid.h"
#include "Comet.h"
#include "BlackHole.h"
#include "Planet.h"
#include "Sun.h"
#include "pch.h"

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
             << " 1: int\n"
             << " 2: double\n"
             << " 3: string\n"
			 << " 4: Asteroid\n"
			 << " 5: Meteor\n"
			 << " 6: Bolid\n"
			 << " 7: Comet\n"
			 << " 8: Black Hole\n"
			 << " 9: Planet\n"
			 << "10: Star\n"
			 << "11: Sun\n"
             << "\n 0: Exit program" << endl;
		inputSafe(cin, answer);
        switch (answer) {
            case 1: {
                Interface<int> temp;
                if(!temp.work())
                    return;
                break;
            }
            case 2: {
                Interface<double> temp;
                if(!temp.work())
                    return;
                break;
            }
            case 3: {
                Interface<std::string> temp;
                if(!temp.work())
                    return;
                break;
            }
			case 4: {
				Interface<Asteroid> temp;
				if (!temp.work())
					return;
				break;
			}
			case 5: {
				Interface<Meteor> temp;
				if (!temp.work())
					return;
				break;
			}
			case 6: {
				Interface<Bolid> temp;
				if (!temp.work())
					return;
				break;
			}
			case 7: {	
				Interface<Comet> temp;
				if (!temp.work())
					return;
				break;
			}
			case 8: {
				Interface<BlackHole> temp;
				if (!temp.work())
					return;
				break;
			}
			case 9: {
				Interface<Planet> temp;
				if (!temp.work())
					return;
				break;
			}
			case 10: {
				Interface<Star> temp;
				if (!temp.work())
					return;
				break;
			}
			case 11: {
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
    int answer;

    do {
		system("cls");
        cout << "Menu: \n"
             << "1: Add item\n"
             << "2: Pop item\n"
             << "3: Show tree\n"
             << "4: Delete tree\n"
             << "5: Exit to MainMenu\n"
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
                tree.show();
				system("pause");
                break;
            }
            case 4: {
                tree.destroyTree(tree.getRoot());
                break;
            }
            case 5: {
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
