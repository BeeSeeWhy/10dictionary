#include <iostream>
#include "bst3.h"
using namespace std;

template <class ItemType>
void BST<ItemType>::insert(Node *&nodePtr, Node* &newNode)
{
    if (nodePtr == nullptr)
        nodePtr = newNode;
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);
} // end insert

template <class ItemType>
void BST<ItemType>::add(ItemType item)
{
    Node* newNode = nullptr;
    newNode = new Node;
    newNode->value = item;
    newNode->left = newNode->right = nullptr;
    insert(root, newNode);
} // end insertNode

template <class ItemType>
void BST<ItemType>::destroySubTree(Node* nodePtr)
{
    if (nodePtr)
    {
        if (nodePtr->left)
            destroySubTree(nodePtr->left);
        if (nodePtr->right)
            destroySubTree(nodePtr->right);
        delete nodePtr;
    } // end if
} // end destroySubTree

template <class ItemType>
bool BST<ItemType>::searchNode(ItemType item)
{
    Node* nodePtr = root;

    while (nodePtr)
    {
        if (nodePtr->value == item)
            return true;
        else if (item < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    } // end while
} // end searchNode

template <class ItemType>
void BST<ItemType>::remove(ItemType item)
{
    deleteNode(item, root);
} // end remove

template <class ItemType>
void BST<ItemType>::deleteNode(ItemType item, Node* &nodePtr)
{
    if (item < nodePtr->value)
        deleteNode(item, nodePtr->left);
    else if (item > nodePtr->value)
        deleteNode(item, nodePtr->right);
    else
        makeDeletion(nodePtr);
} // end deleteNode

template <class ItemType>
void BST<ItemType>::makeDeletion(Node* &nodePtr)
{
    Node* tempNodePtr = nullptr;

    if (nodePtr == nullptr)
        cout << "Cannot delete empty node.\n";

    else if (nodePtr->right == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    } // end else if

    else if (nodePtr->left == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    } // end else if

    else
    {
        tempNodePtr = nodePtr->right;
        while (tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    } // end else
}  // end makeDeletion

template <class ItemType>
void BST<ItemType>::displayInOrder(Node *nodePtr) const
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << endl;
        displayInOrder(nodePtr->right);
    } // end if
} // end displayInOrder

template <class ItemType>
void BST<ItemType>::displayPreOrder(Node* nodePtr) const
{
    if (nodePtr)
    {
        cout << nodePtr->value << endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    } // end if
} // end displayPreOrder

template <class ItemType>
void BST<ItemType>::displayPostOrder(Node* nodePtr) const
{
    if (nodePtr)
    {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << endl;
    } // end if
} // end displayPostOrder

template <class ItemType>
int BST<ItemType>::nodesCountHelper(Node* root)
{
    if (!root) return 0;
    else return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
} // end nodesCountHeler

template <class ItemType>
int BST<ItemType>::nodesCount()
{
    return nodesCountHelper(root);
} // end nodesCount

template class BST<string>;
