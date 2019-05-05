#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;

template <class KeyType, class ValueType>
class BST
{
private:
    struct Node
    {
        KeyType key;
        ValueType value;
        Node* left;
        Node* right;
    }; //end struct

    Node* root;

    void insert(Node* &nodePtr, Node* &newPtr);
    void destroySubTree(Node* nodePtr);
    void deleteNode(KeyType key, Node* &nodePtr);
    void makeDeletion(Node *&);
    void displayInOrder(Node *nodePtr) const;
    void displayPreOrder(Node *nodePtr) const;
    void displayPostOrder(Node *nodePtr) const;
    int nodesCountHelper(Node *root);

public:
    BST()
        { root = nullptr; }
    ~BST()
        { destroySubTree(root); }

    void add(KeyType key, ValueType value);
    bool searchNode(KeyType key);
    void remove(KeyType key);

    void displayInorder() const
        { displayInOrder(root); }
    void displayPreorder() const
        { displayPreOrder(root); }
    void displayPostorder() const
        { displayPostOrder(root); }
    int nodesCount();
};
#endif
