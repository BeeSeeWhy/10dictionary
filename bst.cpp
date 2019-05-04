#include <iostream>
#include <math.h>
#include "Node.h"
//#include "Person.h"
using namespace std;

template <class ItemType>
class BST
{
private:
    Node<ItemType> *root;
    void addHelper(Node<ItemType> *root, ItemType val)
    {
        if (root->value > val)
        {
            if (!root->left)
                root->left = new Node<ItemType>(val);
            else
                addHelper(root->left, val);
        } // end if
        else
        {
            if (!root->right)
                root->right = new Node<ItemType>(val);
            else
                addHelper(root->right, val);
        } // end else
    }

    void printHelper(Node<ItemType> *root)
    {
        if (!root)
          return;
        printHelper(root->left);
        cout << root->value << ' ';
        printHelper(root->right);
    } // end printHelper

    int nodesCountHelper(Node<ItemType> *root) {
        if (!root) return 0;
        else return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
    }

    int heightHelper(Node<ItemType> *root) {
        if (!root) return 0;
        else return 1 + max(heightHelper(root->left), heightHelper(root->right));
    }

    void printMaxPathHelper(Node<ItemType> *root) {
        if (!root) return;
        cout<<root->value<<' ';
        if (heightHelper(root->left) > heightHelper(root->right)) {
            printMaxPathHelper(root->left);
        } else {
            printMaxPathHelper(root->right);
        }
    }

    bool deleteValueHelper(Node<ItemType>* parent, Node<ItemType>* current, ItemType value) {
        if (!current) return false;
        if (current->value == value) {
            if (current->left == NULL || current->right == NULL) {
                Node<ItemType>* temp = current->left;
                if (current->right) temp = current->right;
                if (parent) {
                    if (parent->left == current) {
                        parent->left = temp;
                    } else {
                        parent->right = temp;
                    }
                } else {
                    this->root = temp;
                }
            } else {
                Node<ItemType>* validSubs = current->right;
                while (validSubs->left) {
                    validSubs = validSubs->left;
                }
                ItemType temp = current->value;
                current->value = validSubs->value;
                validSubs->value = temp;
                return deleteValueHelper(current, current->right, temp);
            }
            delete current;
            return true;
        }
        return deleteValueHelper(current, current->left, value) ||
               deleteValueHelper(current, current->right, value);
    }

    public:
    void add(ItemType val) {
        if (root) {
            this->addHelper(root, val);
        } else {
            root = new Node<ItemType>(val);
        }
    }

    void print() {
        printHelper(this->root);
    }

    int nodesCount() {
        return nodesCountHelper(root);
    }

    int height() {
        return heightHelper(this->root);
    }

    void printMaxPath() {
        printMaxPathHelper(this->root);
    }

    bool deleteValue(ItemType value) {
        return this->deleteValueHelper(NULL, this->root, value);
    }
};

int main() {
    BST<int> *bst = new BST<int>();
    bst->add(11);
    bst->add(1);
    bst->add(6);
    bst->add(-1);
    bst->add(-10);
    bst->add(100);
    bst->print();
    cout<<endl;
    cout<<"Nodes count: "<<bst->nodesCount();
    cout<<endl;
    cout<<"Height: "<<bst->height();
    cout<<endl;
    cout<<"Max path: ";
    bst->printMaxPath();
    cout<<endl;
    bst->deleteValue(11);
    cout<<"11 removed: ";
    bst->print();
    cout<<endl;
    cout<<"1 removed: ";
    bst->deleteValue(1);
    bst->print();
    cout<<endl;
    cout<<"-1 removed: ";
    bst->deleteValue(-1);
    bst->print();
    cout<<endl;
    cout<<"6 removed: ";
    bst->deleteValue(6);
    bst->print();
    cout<<endl;
    cout<<"-10 removed: ";
    bst->deleteValue(-10);
    bst->print();
    cout<<endl;
    cout<<"100 removed: ";
    bst->deleteValue(100);
    bst->print();
    cout<<endl;

    return 0;
}
