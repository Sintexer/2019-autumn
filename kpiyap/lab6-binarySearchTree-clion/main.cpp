#include <iostream>
#include "Tree.h"
#include "Interface.h"
#include <list>
int main() {
    /*Interface<int> interface;
    interface.launch();*/
    /*std::list<int> ls;
    ls.push_back(1);
    ls.push_back(2);
    ls.push_back(3);
    auto it = ls.begin();
    std::list<int>::iterator in;
    in =  it++;
    std::cout << *in << endl;
    std::cout << *it << endl;
    */
    Tree<int> tr;
    tr.insert(10);
    tr.insert(15);
    tr.insert(5);
    tr.insert(17);
    tr.insert(12);
    tr.insert(7);
    tr.insert(2);
    tr.show();
    Tree<int>::iterator it = tr.begin();
    /*for (it = tr.begin(); it != tr.end(); ++it)
        cout << *it << "++";
    for (; it != tr.begin(); --it)
        cout << *it << "--";*/
    it+=4;
    cout << *it << endl;
    it-=2;
    cout << *it << endl;
    --it;
    cout << *it << endl;
    --it;
    cout << *it << endl;




    /*cout << endl;
    --it;
    cout << *it << " ";
    --it;
    cout << *it << " ";
    --it;
    cout << *it << " ";
    cout << *it << " ";
    --it;
    cout << *it << " ";
    --it;
    cout << *it << " ";
    --it;
    cout << *it << " "<< endl;
    --it;
    cout << *it << " " ;
    ++it;
    cout << *it << " ";
    ++it;
    cout << *it << " ";
    ++it;
    cout << *it << " ";
    ++it;
    cout << *it << " ";
    ++it;
    cout << *it << " ";
    ++it;
    cout << *it << " ";
    ++it;
    cout << *it << " ";*/
    /*for (; it!=tr.begin(); --it)
        cout << *it << " ";*/
/*    cout << *it << endl;
    ++it;
    cout << *it << endl;
    ++it;
    cout << *it << endl;
    ++it;
    cout << *it << endl;
    ++it;
    cout << *it << endl;*/
    return 0;
}