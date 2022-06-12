// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 9.2


#pragma once
#include "Tree.h"
#include <iostream>
using namespace std;

template<class T>
class SearchTree : public Tree<T>
{
public:
//    virtual methods

    virtual void insert(T value);

    virtual bool  search(T value) { return (search(Tree<T>::root, value) != nullptr);}

    virtual void remove(T val);

    virtual void remove(typename Tree<T>::Node * node);

//    typename Tree<T>::Node * remove(typename Tree<T>::Node * node, T val);

//    successor
    typename Tree<T>::Node * successor(typename Tree<T>::Node * node);
    T successor(T value);

//    minimum
    typename Tree<T>::Node * minimum(typename Tree<T>::Node * node);

//    delete duplicate
    void deleteDuplicates();

    void deleteDuplicates(typename Tree<T>::Node * node);


private:
    void add(typename Tree<T>::Node* current, T val);

    typename Tree<T>::Node* search(typename Tree<T>::Node* current, T val);
};

template <class T>
void SearchTree<T>::insert(T val)
{
    // add value to binary search tree
    if (!Tree<T>::root)
    {
        Tree<T>::root = new typename Tree<T>::Node(val);
        return;
    }
    add(Tree<T>::root, val);
}

template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
{
    if (current->value < val)

        if (!current->right)
        {
            current->right = new typename Tree<T>::Node(val);
            current->right->parent = current;
            return;
        }
        else add(current->right, val);
    else

    if (!current->left)
    {
        current->left = new typename Tree<T>::Node(val);
        current->left->parent = current;
        return;
    }
    else add(current->left, val);
}


// minimum

template<class T>
typename Tree<T>::Node *SearchTree<T>::minimum(typename Tree<T>::Node *node) {
    auto current = node;
    while(current->left) {
        current = current->left;
    }
    return current;
}

template<class T>
typename Tree<T>::Node *SearchTree<T>::successor(typename Tree<T>::Node *node) {
    if(node->right) {
        return minimum(node->right);
    }
    auto parent = node->parent;
    while(parent && node == parent->right) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

template<class T>
void SearchTree<T>::remove(T val) {
    typename Tree<T>::Node * node = SearchTree<T>::search(Tree<T>::root, val);
//    if the node is null the value doesn't exist
//    we exit the function
    if(node == nullptr) {
        return;
    }
//    if node is a leaf: node has no child
    if(node->left == nullptr && node->right == nullptr) {
//        if the node is root
//      set root to be null and delete node
        if(node == Tree<T>::root) {
            Tree<T>::root = nullptr;
            delete node;
            return;
        }
//        if node is not root
//      set the ptr from parent to node to be null and delete node
        auto parent = node->parent;
        if(node == parent->left) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete node;
        return;
//        if the node has one child, left
    } else if(node->right == nullptr) {
//        if the node is root
        if(node == Tree<T>::root) {
            Tree<T>::root = node->left;
            delete node;
            return;
        }
//        if the node is not root
        auto parent = node->parent;
//        set the ptr to node to be the child of node
        if(node == parent->left) {
            parent->left = node->left;
        } else {
            parent->right = node->left;
        }
        delete node;
    } else if(node->left == nullptr) {
        //        if the node is root
        if(node == Tree<T>::root) {
            Tree<T>::root = node->right;
            delete node;
            return;
        }
//        if the node is not root
        auto parent = node->parent;
//        set the ptr to node to be the child of node
        if(node == parent->left) {
            parent->left = node->right;
        } else {
            parent->right = node->right;
        }
        delete node;
//        if the node has two child
    } else {
        typename Tree<T>::Node* successor = SearchTree<T>::successor(node);
        node->value = successor->value;
//        deleting successor
        auto parent = successor->parent;
        if(parent->left == successor) {
            if(successor->left) {
                parent->left = successor->left;
            } else {
                parent->left = successor->right;
            }
        } else {
            if(successor->left) {
                parent->right = successor->left;
            } else {
                parent->right = successor->right;
            }
        }

    }
}


template<class T>
void SearchTree<T>::deleteDuplicates() {
    deleteDuplicates(Tree<T>::root);

}


template<class T>
T SearchTree<T>::successor(T value) {
    typename Tree<T>::Node * node = search(Tree<T>::root, value);
    typename Tree<T>::Node * temp = successor(node);
    if(temp == nullptr)
        throw "no successor";
    return temp->value;
}

template<class T>
typename Tree<T>::Node *SearchTree<T>::search(typename Tree<T>::Node *current, T val) {
    // see if argument value occurs in tree
    if (!current)
        return nullptr;	// not found
    if (current->value == val)
        return current;
    if (current->value < val)
        return search(current->right, val);
    else
        return search(current->left, val);
}

template<class T>
void SearchTree<T>::deleteDuplicates(typename Tree<T>::Node *node) {
    if(node == nullptr)
        return;
    if(node->left)
        deleteDuplicates(node->left);
    if(node->right) {
        deleteDuplicates(node->right);
    }
    if(node->left) {
        typename Tree<T>::Node * duplicate = search(node->left, node->value);
        remove(duplicate);
    }


}

template<class T>
void SearchTree<T>::remove(typename Tree<T>::Node *node) {
    //    if the node is null the value doesn't exist
//    we exit the function
    if(node == nullptr) {
        return;
    }
//    if node is a leaf: node has no child
    if(node->left == nullptr && node->right == nullptr) {
//        if the node is root
//      set root to be null and delete node
        if(node == Tree<T>::root) {
            Tree<T>::root = nullptr;
            delete node;
            return;
        }
//        if node is not root
//      set the ptr from parent to node to be null and delete node
        auto parent = node->parent;
        if(node == parent->left) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete node;
        return;
//        if the node has one child, left
    } else if(node->right == nullptr) {
//        if the node is root
        if(node == Tree<T>::root) {
            Tree<T>::root = node->left;
            delete node;
            return;
        }
//        if the node is not root
        auto parent = node->parent;
//        set the ptr to node to be the child of node
        if(node == parent->left) {
            parent->left = node->left;
        } else {
            parent->right = node->left;
        }
        delete node;
    } else if(node->left == nullptr) {
        //        if the node is root
        if(node == Tree<T>::root) {
            Tree<T>::root = node->right;
            delete node;
            return;
        }
//        if the node is not root
        auto parent = node->parent;
//        set the ptr to node to be the child of node
        if(node == parent->left) {
            parent->left = node->right;
        } else {
            parent->right = node->right;
        }
        delete node;
//        if the node has two child
    } else {
        typename Tree<T>::Node* successor = SearchTree<T>::successor(node);
        node->value = successor->value;
//        deleting successor
        auto parent = successor->parent;
        if(parent->left == successor) {
            if(successor->left) {
                parent->left = successor->left;
            } else {
                parent->left = successor->right;
            }
        } else {
            if(successor->left) {
                parent->right = successor->left;
            } else {
                parent->right = successor->right;
            }
        }

    }
}




