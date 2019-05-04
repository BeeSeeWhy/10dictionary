#ifndef _NODE
#define _NODE

template <class ItemType>
class Node
{
public:
    ItemType value;
    Node* left;
    Node* right;
    Node(ItemType val)
      { this->value = val; }
    Node(ItemType val, Node<ItemType>* left, Node<ItemType>* right)
      { this->value = val;
        this->left = left;
        this->right = right; }
};
#endif
