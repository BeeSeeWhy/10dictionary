#ifndef BST3_H
#define BST3_H
#include <iostream>
using namespace std;

template <class ItemType>
class BST
{
private:
    struct Node
    {
        ItemType value;
        Node* left;
        Node* right;
    }; //end struct

    Node* root;

    void insert(Node* &nodePtr, Node* &newPtr);
    void destroySubTree(Node* nodePtr);
    void deleteNode(ItemType, Node* &);
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

    void add(ItemType value);
    bool searchNode(ItemType value);
    void remove(ItemType value);

    void displayInOrder() const
        { displayInOrder(root); }
    void displayPreOrder() const
        { displayPreOrder(root); }
    void displayPostOrder() const
        { displayPostOrder(root); }
    int nodesCount();
};
#endif
