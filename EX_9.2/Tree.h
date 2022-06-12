// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 9.2


#pragma once
#include <iostream>
#include <queue>

//-----------------------------------
//  class Tree (Binary Trees)
// process nodes in Pre/In/Post  order
//-----------------------------------
template <class T>
class Tree
{
protected:
    //--------------------------------------------------------
    //  inner class Node
    //      a single Node from a binary tree
    //--------------------------------------------------------
    class Node
    {
    public:
        Node* left;
        Node* right;
        Node* parent;
        T value;
        Node(T val) : value(val), left(nullptr), right(nullptr),parent(nullptr) {}
        Node(T val, Node* l, Node* r): value(val), left(l), right(r) {}
//        operator overloading
        bool operator==(const Node &other) {
            return (this->value == other.value && this->right == other.right && this->left == other.left);
        }
    };		//end of Node class

    //data member of tree
    Node* root;

public:
    Tree() { root = nullptr; }	 // initialize tree
    ~Tree();
    int isEmpty() const;
    void clear() { clear(root); root = nullptr; }
    void preOrder() { preOrder(root); }

    virtual void inOrder() { inOrder(root); }
    void postOrder() { postOrder(root); }

    virtual void process(T val) { std::cout << val << std::endl; }

    virtual void insert(T val) = 0;
    virtual bool search(T val) = 0;
    virtual void remove(T val) = 0;

    int height(Node * ptr);
    int height() { return height(root);};
    int max(int a, int b) { return (a > b) ? a : b; }
    void reflect(Node * ptr);
    void reflect() { reflect(Tree<T>::root); };
    void breadthScan(Node * ptr);
    void breadthScan() { breadthScan(Tree<T>::root);};


private:
    //private function for not give acsses to user
    void  clear(Node* current);
    void  preOrder(Node* current);
    void  inOrder(Node* current);
    void  postOrder(Node* current);

};

//----------------------------------------------------------
//  class Tree implementation
//----------------------------------------------------------
template <class T>
Tree<T>::~Tree() // deallocate tree
{
    if (root != NULL)
        clear(root);
}

template <class T>
void Tree<T>::clear(Node* current)
{
    if (current)
    {    // Release memory associated with children
        if (current->left)
            clear(current->left);
        if (current->right)
            clear(current->right);
        delete current;
    }
}

template <class T>
int Tree<T>::isEmpty() const
{
    return  root == NULL;
}

// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node* current)
{    // visit Node, left child, right child
    if (current)
    {   // process current Node
        process(current->value);
        // then visit children
        preOrder(current->left);
        preOrder(current->right);
    }
}

// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node* current)
{    // visit left child, Node, right child
    if (current)
    {
        inOrder(current->left);
        process(current->value);
        inOrder(current->right);
    }
}

// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(Node* current)
{    // visit left child, right child, node
    if (current)
    {
        postOrder(current->left);
        postOrder(current->right);
        process(current->value);
    }
}

template<class T>
int Tree<T>::height(Node * ptr) {
    if(ptr == nullptr) {
        return -1;
    }
    return max(height(ptr->left), height(ptr->right)) + 1;
}

template<class T>
void Tree<T>::reflect(Tree::Node *ptr) {
    if(ptr == nullptr)
        return;
    Tree::Node *temp = ptr->right;
    ptr->right = ptr->left;
    ptr->left = temp;
    reflect(ptr->left);
    reflect(ptr->right);
    return;
}

template<class T>
void Tree<T>::breadthScan(Tree<T>::Node *root) {
    // Base Case
    if (root == nullptr)
        return;
    // Create an empty queue for level order traversal
    std::queue<Node*> q;
    // Enqueue Root and initialize height
    q.push(root);
    while (!q.empty()) {
        // Print front of queue and remove it from queue
        Node* node = q.front();
        std::cout << node->value << " ";
        q.pop();

        /* Enqueue left child */
        if (node->left != nullptr)
            q.push(node->left);

        /*Enqueue right child */
        if (node->right != nullptr)
            q.push(node->right);
    }
}


