#include <iomanip>
#include <iostream>
#include "bst.h"
#include "Entry.h"
using namespace std;

template <class KeyType, class ValueType>
void BST<KeyType, ValueType>::insert(Node* nodePtr, Node* newNode)
{
    if (nodePtr == nullptr)
        nodePtr = newNode;
    else if (newNode->key < nodePtr->key)
        insert(getLeftChildPtr(nodePtr), newNode);
    else
        insert(getRightChildPtr(nodePtr), newNode);
} // end insert

template <class KeyType, class ValueType>
void BST<KeyType, ValueType>::add(KeyType searchKey, ValueType item)
{
    Node* newNode = nullptr;
    newNode = new Node;
    newNode->value = item;
    newNode->key = searchKey;
    setLeftChildPtr(newNode, nullptr);
    setRightChildPtr(newNode, nullptr);
    insert(root, newNode);
} // end insertNode

template <class KeyType, class ValueType>
void BST<KeyType, ValueType>::destroySubTree(Node* nodePtr)
{
    if (nodePtr)
    {
        if (nodePtr->leftPtr)
            destroySubTree(nodePtr->leftPtr);
        if (nodePtr->rightPtr)
            destroySubTree(nodePtr->rightPtr);
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
            nodePtr = nodePtr->leftPtr;
        else
            nodePtr = nodePtr->rightPtr;
    } // end while
    return false;
} // end searchNode

template <class KeyType, class ValueType>
bool BST<KeyType, ValueType>::remove(KeyType searchKey)
{
    bool isSuccessful = false;
    root = removeValue(searchKey, root, isSuccessful);
    return isSuccessful;
} // end remove

/*template <class KeyType, class ValueType>
Node* BST<KeyType, ValueType>::removeValue(KeyType searchKey, Node* subTreePtr,
                              bool isSuccessful)
{
    //cout << " we are here\n";
    if (subTreePtr == nullptr)
    {
        isSuccessful = false;
    }
    else if (subTreePtr->key == searchKey)
    {
        subTreePtr = removeNode(subTreePtr);
        isSuccessful = true;
    }
    else if (subTreePtr->key > searchKey)
    {
        Node* tempPtr = removeValue(getLeftChildPtr(subTreePtr), searchKey, isSuccessful);
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else
    {
        Node* tempPtr = removeValue(getRightChild(subTreePtr), searchKey, isSuccessful);
        subTreePtr->setRightChildPtr(tempPtr);
    }
    return subTreePtr;
} // end removeValue

template <class KeyType, class ValueType>
Node* BST<KeyType, ValueType>::removeNode(Node* nodePtr)
{
    //cout << " we are here\n";
    // nodePtr is a leaf
    if (getLeftChildPtr(nodePtr) == nullptr && getRightChildPtr(nodePtr) == nullptr)
    {
        delete nodePtr;
        nodePtr = nullptr;
        return nodePtr;
    } // end if
    // nodePtr has one child
    else if (getLeftChildPtr(nodePtr) == nullptr || getRighChild(nodePtr) == nullptr)
    {
        Node* nodeToConnectPtr = nullptr;
        if (getRighChild(nodePtr) == nullptr)
            Node* nodeToConnectPtr = getLeftChildPtr(nodePtr);
        else
            Node* nodeToConnectPtr = getRighChildPtr(nodePtr);
        delete nodePtr;
        return nodeToConnectPtr;
    } // end else if
    else // nodePtr has two children
    {
        Node* rightChild = getRightChildPtr(nodePtr);
        Node* tempPtr = removeLeftMostNode(rightChild, rightChild->key);
        nodePtr->setRightChildPtr(tempPtr);
        nodePtr->value = rightChild->key;
        return nodePtr;
    } // end else
}  // end makeDeletion

template <class KeyType, class ValueType>
Node* BST<KeyType, ValueType>::removeLeftMostNode(Node* nodePtr, KeyType inorderSuccessor)
{
    if (getLeftChildPtr(nodePtr) == nullptr)
    {
        inorderSuccessor = nodePtr->key;
        return removeNode(nodePtr);
    } // end if
    else
    {
        Node* tempPtr = removeLeftMostNode(getLeftChildPtr(nodePtr), inorderSuccessor);
        nodePtr->setLeftChildPtr(tempPtr);
        return nodePtr;
    } // end else
} // end removeLeftMostNode */

template <class KeyType, class ValueType>
void BST<KeyType, ValueType>::displayInOrder(Node *nodePtr) const
{
    if (nodePtr)
    {
        cout << "we are here\n";
        displayInOrder(getLeftChildPtr(nodePtr));
        cout << "Name: " << left << setw(10) << nodePtr->key;
        cout << "   Birthday Month: " << nodePtr->value << endl;
        displayInOrder(getRightChildPtr(nodePtr));
    } // end if
} // end displayInOrder

template <class KeyType, class ValueType>
void BST<KeyType, ValueType>::displayPreOrder(Node* nodePtr) const
{
    if (nodePtr)
    {
        cout << "Name: " << left << setw(10)<< nodePtr->key;
        cout << "   Birthday Month: " << nodePtr->value << endl;
        displayPreOrder(nodePtr->leftPtr);
        displayPreOrder(nodePtr->rightPtr);
    } // end if
} // end displayPreOrder

template <class KeyType, class ValueType>
void BST<KeyType, ValueType>::displayPostOrder(Node* nodePtr) const
{
    if (nodePtr)
    {
        displayPostOrder(nodePtr->leftPtr);
        displayPostOrder(nodePtr->rightPtr);
        cout << "Name: " << left << setw(10) << nodePtr->key;
        cout << "Birthday Month: " << nodePtr->value << endl;
    } // end if
} // end displayPostOrder

template <class KeyType, class ValueType>
int BST<KeyType, ValueType>::nodesCountHelper(Node* root)
{
    if (!root) return 0;
    else return 1 + nodesCountHelper(root->leftPtr) + nodesCountHelper(root->rightPtr);
} // end nodesCountHeler

template <class KeyType, class ValueType>
int BST<KeyType, ValueType>::nodesCount()
{
    return nodesCountHelper(root);
} // end nodesCount

template class BST<string, string>;
//template class BST<Entry<class KeyType, class ValueType> >;
