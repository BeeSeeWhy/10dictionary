#include <iomanip>
#include <iostream>
#include "bst.h"
#include "Entry.h"
using namespace std;

template <class KeyType, class ValueType>
void BST<KeyType, ValueType>::insert(Node *&nodePtr, Node* &newNode)
{
    if (nodePtr == nullptr)
        nodePtr = newNode;
    else if (newNode->key < nodePtr->key)
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);
} // end insert

template <class KeyType, class ValueType>
void BST<KeyType, ValueType>::add(KeyType searchKey, ValueType item)
{
    Node* newNode = nullptr;
    newNode = new Node;
    newNode->value = item;
    newNode->key = searchKey;
    newNode->left = newNode->right = nullptr;
    insert(root, newNode);
} // end insertNode

template <class KeyType, class ValueType>
void BST<KeyType, ValueType>::destroySubTree(Node* nodePtr)
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

template <class KeyType, class ValueType>
bool BST<KeyType, ValueType>::searchNode(KeyType searchKey)
{
    Node* nodePtr = root;

    while (nodePtr)
    {
        if (nodePtr->key == searchKey)
            return true;
        else if (searchKey < nodePtr->key)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    } // end while
    return false;
} // end searchNode

template <class KeyType, class ValueType>
void BST<KeyType, ValueType>::remove(KeyType searchKey)
{
    deleteNode(searchKey, root);
} // end remove

template <class KeyType, class ValueType>
void BST<KeyType, ValueType>::deleteNode(KeyType searchKey, Node* &nodePtr)
{
    //cout << " we are here\n";
    if (searchKey < nodePtr->key)
    {
        //cout << "we are here\n";
        deleteNode(searchKey, nodePtr->left);
    }
    else if (searchKey > nodePtr->key)
        deleteNode(searchKey, nodePtr->right);
    else
        makeDeletion(nodePtr);
} // end deleteNode

template <class KeyType, class ValueType>
void BST<KeyType, ValueType>::makeDeletion(Node* &nodePtr)
{
    //cout << " we are here\n";
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

template <class KeyType, class ValueType>
void BST<KeyType, ValueType>::displayInOrder(Node *nodePtr) const
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << "Name: " << left << setw(10) << nodePtr->key;
        cout << "   Birthday Month: " << nodePtr->value << endl;
        displayInOrder(nodePtr->right);
    } // end if
} // end displayInOrder

template <class KeyType, class ValueType>
void BST<KeyType, ValueType>::displayPreOrder(Node* nodePtr) const
{
    if (nodePtr)
    {
        cout << "Name: " << left << setw(10)<< nodePtr->key;
        cout << "   Birthday Month: " << nodePtr->value << endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    } // end if
} // end displayPreOrder

template <class KeyType, class ValueType>
void BST<KeyType, ValueType>::displayPostOrder(Node* nodePtr) const
{
    if (nodePtr)
    {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << "Name: " << left << setw(10) << nodePtr->key;
        cout << "Birthday Month: " << nodePtr->value << endl;
    } // end if
} // end displayPostOrder

template <class KeyType, class ValueType>
int BST<KeyType, ValueType>::nodesCountHelper(Node* root)
{
    if (!root) return 0;
    else return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
} // end nodesCountHeler

template <class KeyType, class ValueType>
int BST<KeyType, ValueType>::nodesCount()
{
    return nodesCountHelper(root);
} // end nodesCount

template class BST<string, string>;
//template class BST<Entry<class KeyType, class ValueType> >;
