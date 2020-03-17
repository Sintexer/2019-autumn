#pragma once
#include <iostream>
#include <exception>
#include <stack>

template <typename T>
class Tree {
private:

    template <typename N>
    class Node{
        // Класс узла, в котором хранится значение шаблонного типа
        // а также два указателя, налево и направо
        // слева храннится елемент, который меньше элемента в узла
        // справа наоборот
    public:
        N value{};
        Node<N>* left{nullptr}, *right{nullptr};
        Node<N>* parent{};
        Node() = default;
        Node(T val, Node<T>* lef, Node<T>* rgt, Node<T>* prnt):value(val), left(lef), right(rgt), parent(prnt) {}
        ~Node(){
            delete left, right, parent;
        }
    };

    Node<T>* root;
    // В этой переменной хранится корень дерева

protected:
    // Методы, размещенные в protected части класса,
    // не предназначены для глаз пользователя
    // Производят реализацию удаления, поиска, вставки, извлечения

    void popItem(Node<T>*& tree, T val);
    // Данный метод рекурсивно ищет узел со значением val
    // При нахождении узла вызывает по отношению к нему метод deleteNode
    // Тем самым данный метод производит поиск нужного для удаления узла

    void insertItem(Node<T>*& tree, T newItem, Node<T>* prnt);
    // Данный метод рекурсивно ищет узел со значением newItem
    // Если такой узел существует, то значение не вставляется
    // Если же такого узла нет, то метод остановится на узле со значением nullptr
    // В который можно вставить новое значение, не нарушая структуру дерева поиска

    void extractMostLeft(Node<T>*& node, T&  val);
    // Копирует значение самого левого от node узла, а затем удаляет этот самый левый узел
    // Данный метод необходим для удаления узла с двумя наследниками

    void deleteNode(Node<T>*& node);
    // Удалает переданную в метод ноду
    // Обрабатывает 4 ситуации:
    //   1) Нода не имеет наследников
    //   2) Нода имеет только левого наследника
    //   3) Нода имеет только правого наследника
    //   4) Нода имеет 2 наследника
    // Все ситуации, кроме ноера 4 обрабатываются прямо в теле метода
    // Для ситуации 4 используется метод извлечения ноды extractMostLeft

    void nodeAmount(Node<T>*& node, size_t& size);

    /* Добавить исключение */
    void copyTree(Node<T> *tree, Node<T> *& newTree) const;
    // Копирует все ноды дерева tree в дерево newTree

    virtual void printTree(Node<T>* current, int level = 0);
    // Рекурсивный симметриный вывод дерева в консоль (Дерево лежит боком)

public:
    class iterator {
        friend class Tree;
    private:
    Node<T>* current{};
    public:
        iterator(): current(nullptr) {};

        const Tree<T>::iterator operator++();
        const Tree<T>::iterator operator++(int);
        const Tree<T>::iterator operator--();
        const Tree<T>::iterator operator--(int);

        void operator+=(int num);
        void operator-=(int num);

        bool operator==(Tree<T>::iterator rht);
        bool operator!=(Tree<T>::iterator rht);

        T& operator*();
    };

    //
    // M
    // E
    // T
    // H
    // O
    // D
    // S
    //

    Tree(): root(nullptr){}
    Tree(const Tree& tr): root(std::move(tr.root)){}
    explicit Tree(T val);
    virtual ~Tree();
    const Node<T>*& getRoot();
    virtual bool empty();
    /*virtual T getMin();
    // Возвращает наименьшее значение в дереве
    virtual T getMax();
    // Возвращает наибольшее значение в дереве*/
    virtual size_t size();
    // Считает вершины дерева, включая корень

    virtual void insert(T val);
    // Метод вставки значения в дерево
    // Используется protected method insertItem

    virtual void pop(T val);
    // Ищет значение val в дереве и производит удаление ноду

    virtual void show();

    Tree<T>::iterator begin();
    Tree<T>::iterator end();

    void destroyTree(Node<T> *& tree);
    // Очищает все дерево рекурсивно, освобождает память на указатели нод
};

template<typename T>
void Tree<T>::popItem(Node<T>*& tree, T val) {
    if(!tree)
    {
        //Exc
    }
    else if(val == tree->value)
    {
        deleteNode(tree);
    }
    else if(val < tree->value)
        popItem(tree->left, val);
    else
        popItem(tree->right, val);
}

template<typename T>
void Tree<T>::insertItem(Node<T>*& tree, const T newItem, Node<T>* prnt) {
    if(!tree)
    {
        tree = new Node<T>(newItem, nullptr, nullptr, prnt);
    }
    else if (newItem == tree->value)
    {}//raise exception
    else if(newItem < tree->value) {
        prnt = tree;
        insertItem(tree->left, newItem, prnt);
    }
    else {
        prnt = tree;
        insertItem(tree->right, newItem, prnt);
    }
}

template<typename T>
void Tree<T>::extractMostLeft(Tree::Node<T> *&node, T& val) {
    if(!node->left)
    {
        val=node->value;
        Node<T>*& del = node;
        node = node->right;
        node->parent = del->parent;
        del->right = nullptr;
        delete del;
    }
    else
        extractMostLeft(node->left, val);
}

template<typename T>
void Tree<T>::deleteNode(Node<T>*& node) {
    Node<T>* del;
    T replaceVal;
    if(node->left == nullptr && node->right  == nullptr)
    {
        delete node;
        node = nullptr;
    }
    else if(!node->left)
    {
        del = node;
        node = node->right;
        node->parent = del->parent;
        del->right = nullptr;
        delete del;
    }
    else if (!node->right)
    {
        del = node;
        node = node->left;
        node->parent = del->parent;
        del->left = nullptr;
        delete del;
    }
    else
    {
        extractMostLeft(node->right, replaceVal);
        node->value = replaceVal;
    }
}

template<typename T>
void Tree<T>::nodeAmount(Tree::Node<T>*& node, size_t& size) {
    if(node)
    {
        ++size;
        nodeAmount(node->left, size);
        nodeAmount(node->right, size);
    }
}

template<typename T>
void Tree<T>::copyTree(Tree::Node<T> *tree, Tree::Node<T> *&newTree) const {
    if(tree)
    {
        newTree = new Node<T>(tree->value, nullptr, nullptr);
        copyTree(tree->left, newTree->left);
        copyTree(tree->right, newTree->right);
    }
    else
        newTree = nullptr;
}

template<typename T>
void Tree<T>::printTree(Tree::Node<T> *current, int level) {
    if (current)
    {
        printTree(current->left, level + 1);
        for (int i = 0; i < level; i++) std::cout << "    ";
        std::cout << current->value << std::endl;// << " ";
        printTree(current->right, level + 1);
    }
}

template<typename T>
const typename Tree<T>::iterator Tree<T>::iterator::operator++(){
    if (current->parent == nullptr) {
        current = current->right;
        while(current->left)
            current = current->left;
    } // Если итератор указывает на root, то идем в самый левый от правого узел
    else if (current == current->parent->left) {
        if (current->right == nullptr)
            current = current->parent;
        else {
            current = current->right;
            while (current->left)
                current = current->left;
        }
    }// Если итератор указывает на элемент, левый от родительского, то проверяем правый узел
        // Если он пуст - переходим к родителю узла
        // Если не пуст, идем в левый от самого правого
    else if (current == current->parent->right){// Если узел правый от родительского узла
        if(current->right) // то проверяем правый узел
            current=current->right; // Если он есть, то переходим к нему
        else { //Если его нет, то идем вверх по нодам, пока не найдем ноду со значением больше текущего
            T temp = current->value;
            while (current) {
                if (current->value <= temp)
                    current = current->parent;
                else
                    break;
            }
        }
    }
    // Если ноды со значением больше текущего не найдется, то установится значение родителя root'a - nullptr
    // А nullptr соответствует значению Tree.end()
    return *this;
}

template<typename T>
const typename Tree<T>::iterator Tree<T>::iterator::operator++(int) {
    Tree<T>::iterator temp = *this;
    ++(*this);
    return temp;
}

template<typename T>
const typename Tree<T>::iterator Tree<T>::iterator::operator--(){
    if (current->parent == nullptr) {
        current = current->left;
        while (current->right)
            current = current->right;
    }
    else if (current == current->parent->right) {
        if (current->left == nullptr)
            current = current->parent;
        else {
            current = current->left;
            while (current->right)
                current = current->right;
        }
    }// Если итератор указывает на элемент, правый от родительского, то проверяем левый узел
        // Если он пуст - переходим к родителю узла
        // Если не пуст, идем в самый правый от левого
    else if (current == current->parent->left){// Если узел левый от родительского узла
        if(current->left) // то проверяем левый узел
            current=current->left; // Если он есть, то переходим к нему
        else { //Если его нет, то идем вверх по нодам, пока не найдем ноду со значением меньше текущего
            Node<T>* temp = current;
            while (current) {
                if (current->value >= temp->value)
                    current = current->parent;
                else
                    break;
            }
            if (!current)
                current = temp;
        }
    }
    // Если ноды со значением меньше текущего не найдется, то установится значение родителя root'a - nullptr
    // А nullptr соответствует значению Tree.end()
    return *this;
}

template<typename T>
const typename Tree<T>::iterator Tree<T>::iterator::operator--(int) {
    Tree<T>::iterator temp = *this;
    --(*this);
    return temp;
}

template<typename T>
void Tree<T>::iterator::operator+=(int num) {
    if (num<0)
        *this-=(-1*num);
    else
        while(num>0)
        {
            ++(*this);
            --num;
        }
}

template<typename T>
void Tree<T>::iterator::operator-=(int num) {
    if (num<0)
        *this+=(-1*num);
    else
        while(num>0)
        {
            --(*this);
            --num;
        }
}

template<typename T>
bool Tree<T>::iterator::operator==(Tree<T>::iterator rht) {
    return current == rht.current;
}

template<typename T>
bool Tree<T>::iterator::operator!=(Tree<T>::iterator rht) {
    return !(*this==rht);
}

template<typename T>
T &Tree<T>::iterator::operator*()
{
    return current->value;
}

template<typename T>
Tree<T>::Tree(T val) {
    root = new Node<T>(val, nullptr, nullptr);
}

template<typename T>
Tree<T>::~Tree() {
    destroyTree(root);
}

template<typename T>
const typename Tree<T>::template Node<T> *&Tree<T>::getRoot() {
    return root;
}

template<typename T>
bool Tree<T>::empty() {
    return !root;
}

template<typename T>
size_t Tree<T>::size() {
    size_t size{};
    nodeAmount(root, size);
    return size;
}

template<typename T>
void Tree<T>::insert(T val) {
    insertItem(root, val, nullptr);
}

template<typename T>
void Tree<T>::pop(T val) {
    popItem(root, val);
}

template<typename T>
void Tree<T>::show() {
    printTree(getRoot(), 0);
    std::cout << std::endl;
}

template<typename T>
typename Tree<T>::iterator Tree<T>::begin(){
    Tree<T>::iterator it;
    Node<T>* temp = root;
    while(temp->left)
        temp=temp->left;
    it.current = temp;
    return it;
}

template<typename T>
typename Tree<T>::iterator Tree<T>::end() {
    return Tree<T>::iterator();
}

template<typename T>
void Tree<T>::destroyTree(Tree::Node<T> *&tree) {
    if(tree)
    {
        destroyTree(tree->left);
        destroyTree(tree->right);
        delete tree;
        tree = nullptr;
    }
}