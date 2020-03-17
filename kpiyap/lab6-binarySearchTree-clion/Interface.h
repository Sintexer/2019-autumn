#ifndef LAB_6___BINARY_TREE_INTERFACE_H
#define LAB_6___BINARY_TREE_INTERFACE_H

#include <iostream>
#include "Tree.h"
using std::cout;
using std::cin;
using std::endl;

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
        cout << "Choose Tree Node type: \n"
             << "1: int\n"
             << "2: double\n"
             << "3: string\n"
             << "0: Exit program" << endl;
        cin >> answer;
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
            case 0: {
                return;
            }
            default: {
                cout << "\nIncorrect answer, please, try again" << endl;
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
        cout << "Menu: \n"
             << "1: Add item\n"
             << "2: Pop item\n"
             << "3: Show tree\n"
             << "4: Delete tree\n"
             << "5: Exit to MainMenu\n"
             << "0: Exit program"<< endl;
        cin >> answer;
        switch (answer) {
            case 1: {
                T temp;
                cout << "Input item: " << endl;
                cin >> temp;
                tree.insert(temp);
                break;
            }
            case 2: {
                T temp;
                cout << "Input item for pop: " << endl;
                cin >> temp;
                tree.pop(temp);
                break;
            }
            case 3: {
                tree.show();
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
                cout << "\nIncorrect answer, please, try again" << endl;
                break;
            }

        }
    }while(answer);
    return true;
}

#endif //LAB_6___BINARY_TREE_INTERFACE_H
