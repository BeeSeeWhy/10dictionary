#ifndef _SORTED_ARRAY
#define _SORTED_ARRAY
#include <string>
#include "Person.h"

class SortedArray
{
private:
    static const int DEFAULT_CAPACITY = 21;
    Person array[DEFAULT_CAPACITY];
    int elementCount;
public:
    SortedArray();
    SortedArray(Person anArray[]);

    bool isEmpty() const
        { return elementCount == 0; }
    int getCount() const
        { return elementCount; }
    void addPerson(Person newPerson);
    int binarySearch(int first, int last, Person target);

    void printPerson(int index) const;
    void printArray() const;
    void printMonth(std::string aMonth) const;

    void remove(Person target);
};
#endif
