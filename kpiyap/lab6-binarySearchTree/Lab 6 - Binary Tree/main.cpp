#include <iostream>
#include "Tree.h"
int main() {
    Tree<int> tr;
    tr.insert(20);
    tr.insert(8);
    tr.insert(6);
    tr.insert(5);
    tr.insert(7);
    tr.insert(13);
    tr.insert(14);
    tr.insert(9);
    tr.insert(11);
    tr.insert(10);
    tr.insert(12);
    tr.show(tr.getRoot());
    tr.pop(8);
    std::cout << "\n\n\n\n\n";
    tr.show(tr.getRoot());
    tr.pop(11);
    std::cout << "\n\n\n\n\n";
    tr.show(tr.getRoot());
    tr.pop(20);
    std::cout << "\n\n\n\n\n";
    tr.show(tr.getRoot());
    return 0;
}