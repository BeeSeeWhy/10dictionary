#include <iomanip>
#include <iostream>
#include <string>
#include "Person.h"
#include "SortedArray.h"
using namespace std;

int main()
{
    const int DEFAULT_CAPACITY = 21;
    SortedArray entries[DEFAULT_CAPACITY];

    Person Shayna;
    Shayna.setInfo("Shayna", "September", 7);
    entries->addPerson(Shayna);
    cout << "Shayna added: \n";
    entries->printArray();
    cout << endl;

    Person Darra;
    Darra.setInfo("Darra", "November", 4);
    entries->addPerson(Darra);
    cout << "Darra added: \n";
    entries->printArray();
    cout << endl;

    cout << "Searching for Darra...\n";
    int index = entries->binarySearch(0, entries->getCount(), Darra);
    entries->printPerson(index);
    cout << endl;

    Person Jaxon;
    Jaxon.setInfo("Jaxon", "April", 1);
    entries->addPerson(Jaxon);
    cout << "Jaxon added: \n";
    entries->printArray();
    cout << endl;

    Person Brandon;
    Brandon.setInfo("Brandon", "July", 17);
    entries->addPerson(Brandon);
    cout << "Brandon added: \n";
    entries->printArray();
    cout << endl;

    cout << "Element count: " << entries->getCount() << endl << endl;

    Person Kendra;
    Kendra.setInfo("Kendra", "June", 16);
    entries->addPerson(Kendra);
    cout << "Kendra added: \n";
    entries->printArray();
    cout << endl;

    Person Jim;
    Jim.setInfo("Jim", "November", 9);
    entries->addPerson(Jim);
    cout << "Jim added: \n";
    entries->printArray();
    cout << endl;

    cout << "Searching for Brandon...\n";
    int index2 = entries->binarySearch(0, entries->getCount(), Brandon);
    entries->printPerson(index);
    cout << endl;

    cout << "Searching for persons with birthdays in November...\n";
    entries->printMonth("November");

    entries->remove(Jaxon);
    cout << "Jaxon removed: \n";
    entries->printArray();
    return 0;
}
