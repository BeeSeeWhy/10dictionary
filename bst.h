#ifndef BST_H
#define BST_H
#include <iostream>
#include "BinaryNode.h"
using namespace std;

template <class KeyType, class ValueType>
class BST
{
public:
    struct Node
    {
        KeyType key;
        ValueType value;
        Node* leftPtr;
        Node* rightPtr;
    }; //end struct
    Node* root;
private:
    void insert(Node* nodePtr, Node* newPtr);
    void destroySubTree(Node* nodePtr);
    /*Node* removeValue(KeyType key, Node* nodePtr, bool isSuccesful);
    Node* removeNode(Node* nodePtr);
    Node* removeLeftMostNode(Node* nodePtr, KeyType inorderSuccessor);*/
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
    bool remove(KeyType key);
    Node* getLeftChildPtr(Node* nodePtr) const
        { return nodePtr->leftPtr; }
    Node* getRightChildPtr(Node* nodePtr) const
        { return nodePtr->rightPtr; }
    Node* getRoot() const
        { return root; }
    void setLeftChildPtr(Node* nodePtr, Node* newPtr)
        { nodePtr->leftPtr = newPtr; }
    void setRightChildPtr(Node* nodePtr, Node* newPtr)
        { nodePtr->rightPtr = newPtr; }
    void displayInorder() const
        { displayInOrder(getRoot()); }
    void displayPreorder() const
        { displayPreOrder(root); }
    void displayPostorder() const
        { displayPostOrder(root); }
    int nodesCount();
private:
  Node* removeValue(KeyType searchKey, Node* subTreePtr, bool isSuccessful)
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
          Node* tempPtr = removeValue(searchKey, getLeftChildPtr(subTreePtr), isSuccessful);
          setLeftChildPtr(subTreePtr, tempPtr);
      }
      else
      {
          Node* tempPtr = removeValue(searchKey, getRightChildPtr(subTreePtr), isSuccessful);
          setRightChildPtr(subTreePtr, tempPtr);
      }
      return subTreePtr;
  } // end removeValue

  Node* removeNode(Node* nodePtr)
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
      else if (getLeftChildPtr(nodePtr) == nullptr || getRightChildPtr(nodePtr) == nullptr)
      {
          Node* nodeToConnectPtr = nullptr;
          if (getRightChildPtr(nodePtr) == nullptr)
              Node* nodeToConnectPtr = getLeftChildPtr(nodePtr);
          else
              Node* nodeToConnectPtr = getRightChildPtr(nodePtr);
          delete nodePtr;
          return nodeToConnectPtr;
      } // end else if
      else // nodePtr has two children
      {
          Node* rightChild = getRightChildPtr(nodePtr);
          Node* tempPtr = removeLeftMostNode(rightChild, rightChild->key);
          setRightChildPtr(nodePtr, tempPtr);
          nodePtr->value = rightChild->key;
          return nodePtr;
      } // end else
  }  // end makeDeletion

  Node* removeLeftMostNode(Node* nodePtr, KeyType inorderSuccessor)
  {
      if (getLeftChildPtr(nodePtr) == nullptr)
      {
          inorderSuccessor = nodePtr->key;
          return removeNode(nodePtr);
      } // end if
      else
      {
          Node* tempPtr = removeLeftMostNode(getLeftChildPtr(nodePtr), inorderSuccessor);
          setLeftChildPtr(nodePtr, tempPtr);
          return nodePtr;
      } // end else
  } // end removeLeftMostNode
};
#endif
