#pragma once
#include <iostream>
#include <utility>
#include <exception>

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
        Node() = default;
        Node(T val, Node<T>* lef, Node<T>* rgt):value(val), left(lef), right(rgt) {}
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

    void insertItem(Node<T>*& tree, T newItem);
    // Данный метод рекурсивно ищет узел со значением newItem
    // Если такой узел существует, то поднимается исключение
    // Если же такого узла нет, то метод остановится на узле со значением nullptr
    // В который можно вставить новое значение, не нарушая структуру дерева поиска

    void findMin(Node<T>*& node, Tree::Node<T>*& min_node);
    // Ищет узел с наименьшим значением узла в дереве
    // И записывает адрес этого узла в указатель min_node

    void findMax(Node<T>*& node, Tree::Node<T>*& max_node);
    // Ищет узел с наибольшим значением узла в дереве
    // И записывает адрес этого узла в указатель max_node

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

    virtual void printTree(Node<T>* p, int level = 0);
    // Рекурсивный симметриный вывод дерева в консоль (Дерево лежит боком)

public:
    Tree(): root(nullptr){}
    Tree(const Tree& tr): root(std::move(tr.root)){}
    explicit Tree(T val);
    virtual ~Tree();
    Node<T>*& getRoot()
    {
        return root;
    }
    virtual bool empty();

    virtual T getMin();
    // Возвращает наименьшее значение в дереве
    virtual T getMax();
    // Возвращает наибольшее значение в дереве

    virtual size_t size();
    // Считает вершины дерева, включая корень

    virtual void insert(T val);
    // Метод вставки значения в дерево
    // Используется protected method insertItem

    virtual void pop(T val);
    // Ищет значение val в дереве и производит ее удаление

    virtual void show();

    void destroyTree(Node<T> *& tree);
    // Очищает все дерево рекурсивно, освобождает память на указатели нод

    /*
     * Установить корень - выбрасывать исключение, если корень не пустой
     * 3 вида обхода дерева
     * Извлечение элемента по ключу
    */
};

template<typename T>
bool Tree<T>::empty() {
    return !root;
}

template<typename T>
void Tree<T>::printTree(Tree::Node<T> *p, int level) {
    if (p)
    {
        printTree(p->left, level + 1);
        //for (int i = 0; i < level; i++) std::cout << "    ";
        std::cout << p->value << "\n";
        printTree(p->right, level + 1);
    }
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

template<typename T>
Tree<T>::Tree(T val) {
    root = new Node<T>(val, nullptr, nullptr);
}

template<typename T>
Tree<T>::~Tree() {
    destroyTree(root);
}

template<typename T>
void Tree<T>::insert(T val) {
    insertItem(root, val);
}

template<typename T>
void Tree<T>::insertItem(Node<T>*& tree, T newItem) {
    if(!tree)
    {
        tree = new Node<T>(newItem, nullptr, nullptr);
    }
    else if (newItem == tree->value)
    {}//raise exception
    else if(newItem < tree->value)
        insertItem(tree->left, newItem);
    else
        insertItem(tree->right, newItem);
}

template<typename T>
void Tree<T>::pop(T val) {
    popItem(root, val);
}

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
        del->right = nullptr;
        delete del;
    }
    else if (!node->right)
    {
        del = node;
        node = node->left;
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
void Tree<T>::extractMostLeft(Tree::Node<T> *&node, T& val) {
    /*
    Node<T>* temp;
    findMin(node, temp);
     val = temp->value;
    Node<T>* del = temp;
    temp = temp->right;
    del->right = nullptr;
    delete del;
     */
    if(!node->left)
    {
        val=node->value;
        Node<T>* del = node;
        node = node->right;
        del->right = nullptr;
        delete del;
    }
    else
        extractMostLeft(node->left, val);
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
void Tree<T>::findMin(Tree::Node<T> *&node, Tree::Node<T> *&min_node) {
    if(!node->left)
        min_node = node;
    else
        findMin(node->left, min_node);
}

template<typename T>
void Tree<T>::findMax(Node<T>*& node, Node<T>*& max_node) {
    if(!node->right)
        max_node = node;
    else
        findMin(node, max_node);
}

template<typename T>
T Tree<T>::getMin() {
    Node<T>* temp;
    findMin(root, temp);
    return temp->value;
}

template<typename T>
T Tree<T>::getMax() {
    Node<T>* temp;
    findMax(root, temp);
    return temp->value;
}

template<typename T>
size_t Tree<T>::size() {
    size_t size{};
    nodeAmount(root, size);
    return size;
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
void Tree<T>::show() {
    printTree(getRoot(), 0);
    std::cout << std::endl;
}


