#include <iostream>
#include <string>
#include "bst.h"
using namespace std;

int main ()
{
    BST<string, string> *bst = new BST<string, string> ();
    bst->add("Jaxon", "April");
    cout << "Jaxon added\n";
    bst->add("Darra", "November");
    cout << "Darra added\n";
    bst->add("Jim", "November");
    cout << "Jim added\n";
    bst->add("Ava", "April");
    cout << "Ava added\n";
    bst->add("Brandon", "July");
    cout << "Brandon added\n";
    bst->add("Shayna", "September");
    cout << "Shayna added\n";
    bst->displayInorder();
    cout << endl;
    //cout << "got here!!" << endl;
    bst->remove("Ava");
    cout << "Ava removed: \n";
    bst->displayInorder();
    cout << endl;
    cout << "Shayna removed: \n";
    bst->remove("Shayna");
    bst->displayInorder();
    cout << endl;
    cout << "Jim removed: \n";
    bst->remove("Jim");
    bst->displayInorder();
    cout << endl;
    cout<<"Darra removed: \n";
    bst->remove("Darra");
    bst->displayInorder();
    cout << endl;
    cout<<"Brandon removed: \n";
    bst->remove("Brandon");
    bst->displayInorder();
    cout<<endl;
    cout<<"Jaxon removed: \n";
    bst->remove("Jaxon");
    bst->displayInorder();
    cout << endl;

    return 0;
}
