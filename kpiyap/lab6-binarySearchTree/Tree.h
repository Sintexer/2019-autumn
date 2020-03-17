#pragma once
#include <iostream>
#include <utility>
template <typename T>
class Tree {
private:

    template <typename N>
    class Node{
    private:
        N value;
        size_t children;
        Node<N>* left, *right;
        friend class Tree;
    public:
        Node(): left(nullptr), right(nullptr) {}
        Node(T val, Node<T>* lef, Node<T>* rgt):value(val), left(lef), right(rgt) {}
    };


    Node<T>* root;



protected:
    void popItem(Node<T>*& tree, T val);
    void insertItem(Node<T>*& tree, T newItem);
    void mostLeft(Node<T>*& node, T&  val);
    void deleteNode(Node<T>*& node);
    void copyTree(Node<T> *tree, Node<T> *& newTree) const;
    void destroyTree(Node<T> *& tree);

public:
    Tree(): root(nullptr){}
    Tree(T val);
    Tree(const Tree& tr): root(std::move(tr.root)){}
    virtual ~Tree();
    Node<T>* getRoot()
    {
        return root;
    }
    virtual bool empty();

    virtual void insert(T val);
    virtual void pop(T val);

    virtual void show(Node<T>* p, int level = 0);
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
void Tree<T>::show(Tree::Node<T> *p, int level) {
    if (p)
    {
        show(p->left, level + 1);
        for (int i = 0; i < level; i++) std::cout << "    ";
        std::cout << p->value << std::endl;
        show(p->right, level + 1);
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
void Tree<T>::insertItem(Node<T>*& tree, const T newItem) {
    if(!tree)
    {
        tree = new Node<T>(newItem, nullptr, nullptr);
    }
    else if(newItem<tree->value)
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
        mostLeft(node->right, replaceVal);
        node->value = replaceVal;
    }
}

template<typename T>
void Tree<T>::mostLeft(Tree::Node<T> *&node, T& val) {
    if(!node->left)
    {
        val = node->value;
        Node<T>* del = node;
        node = node->right;
        del->right = nullptr;
        delete del;
    }
    else
        mostLeft(node->left, val);
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


