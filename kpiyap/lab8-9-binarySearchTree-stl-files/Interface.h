#pragma once

#include "Exc.h"
#include "Bolid.h"
#include "Comet.h"
#include "BlackHole.h"
#include "Planet.h"
#include "Sun.h"
#include "pch.h"
#include "OutputTable.h"
#include <algorithm>

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
    list<T> lst;
	OutputTable tab("");
    int answer;

    do {
		system("cls");
		cout << "Menu: \n"
			<< "1: Add item\n"
			<< "2: Pop item\n"
			<< "3: Show list\n"
			<< "4: List size\n"
			<< "5: List sort\n"
			<< "6: List reverse\n"
			<< "7: Delete list\n"
			<< "8: Write to file txt\n"
            << "9: Read from txt file\n"
            << "10: Write to binary\n"
            << "11: Read from binary\n"
            << "\n12: Exit to MainMenu\n"
            << "0: Exit program"<< endl;
        inputSafe(cin, answer);
		bool flag{};
        switch (answer) {
            case 1: {
                T temp;
                cout << "Input item: " << endl;
				inputSafe(cin, temp);
				lst.push_back(temp);
                break;
            }
            case 2: {
                T temp;
                cout << "Input item for pop: " << endl;
				inputSafe(cin, temp);
				lst.erase(std::find(lst.begin(), lst.end(), temp));
                break;
            }
            case 3: {
				system("cls");
				typename list<T>::iterator it = lst.begin();
                if(it==lst.end())
                    break;
				tab.clear();
				tab.setHead(dynamic_cast<SpaceObject&>(*it).makeTableHead());
				while(it !=lst.end()){
				    tab.add_str(dynamic_cast<SpaceObject&>(*it).makeStr());
				    it++;
				}
				cout << tab << endl;
				system("pause");
                break;
            }
			case 4: {
				system("cls");
				cout << "List size = " << lst.size() << endl;
				system("pause");
				break;
			}
			case 5: {
				lst.sort();
				break;
			}
			case 6: {
				lst.reverse();
				break;
			}
            case 7: {
                lst.clear();
                break;
            }
            case 8: {
                typename list<T>::iterator it = lst.begin();
                if(it!=lst.end()) {
                    TextFile txt(static_cast<SpaceObject&>(*it).getPath());
                    txt.open_out();
                    while (it != lst.end()) {
                        txt.write(*it);
                        it++;
                    }
                }
                break;
            }
            case 9:{
                T temp;
                TextFile txt(static_cast<SpaceObject&>(temp).getPath());
                txt.open_in();
                lst.clear();
                while(txt.in()){
                    txt.read(temp);
                    lst.push_back(temp);
                }
                break;
            }
            case 10: {
                typename list<T>::iterator it = lst.begin();
                if(it!= lst.end()) {
                    BinaryFile bin(static_cast<SpaceObject &>(*it).getPathBinary());
                    bin.open_out();
                    while(it!=lst.end()){
                        static_cast<SpaceObject&>(*it).writeBin(bin);
                        ++it;
                    }
                }
                break;
            }
            case 11: {
                T temp;
                BinaryFile bin(static_cast<SpaceObject &>(temp).getPathBinary());
                if(!bin.open_in()){
                    cout << "Файл пуст" << endl;
                    break;
                }
                lst.clear();

                while (static_cast<SpaceObject &>(temp).readBin(bin))
                    lst.push_back(temp);
                break;
            }
            case 12: {
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


