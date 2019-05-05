#include <iostream>
#include <string>
#include "bst3.h"
//#include "Node.h"
//#include "Person.h"
//#include "TreeDictionary.h"
using namespace std;

int main() {
    BST<string> *bst = new BST<string>();
    bst->add("Jaxon");
    cout << "Jaxon added\n";
    bst->add("Darra");
    cout << "Darra added\n";
    bst->add("Jim");
    cout << "Jim added\n";
    bst->add("Ava");
    cout << "Ava added\n";
    bst->add("Brandon");
    cout << "Brandon added\n";
    bst->add("Shayna");
    cout << "Shayna added\n";
    bst->displayInOrder();
    cout << endl;
    bst->remove("Ava");
    cout << "Ava removed: \n";
    bst->displayInOrder();
    cout << endl;
    cout << "Shayna removed: \n";
    bst->remove("Shayna");
    bst->displayInOrder();
    cout << endl;
    cout << "Jim removed: \n";
    bst->remove("Jim");
    bst->displayInOrder();
    cout << endl;
    cout<<"Darra removed: \n";
    bst->remove("Darra");
    bst->displayInOrder();
    cout << endl;
    cout<<"Brandon removed: \n";
    bst->remove("Brandon");
    bst->displayInOrder();
    cout<<endl;
    cout<<"Jaxon removed: \n";
    bst->remove("Jaxon");
    bst->displayInOrder();
    cout << endl;

    return 0;
}
