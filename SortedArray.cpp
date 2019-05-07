#include <iomanip>
#include <iostream>
#include <string>
#include "Person.h"
#include "SortedArray.h"

SortedArray::SortedArray()
{
    elementCount = 0;
}

SortedArray::SortedArray(Person anArray[])
{
    for (int i = 0; i < DEFAULT_CAPACITY; i++)
        array[i] = anArray[i];
} // end copy constructor

void SortedArray::addPerson(Person newPerson)
{
    // if array empty
    /*if (elementCount == 0)
    {
        array[0] = newPerson;
        elementCount++;
    } // end if
    // if array not empty
    else
    {*/
        int pos = 0;
        for (int i = 0; i < elementCount; i++)
        {
            if(array[i].getName() <= newPerson.getName() && newPerson.getName() < array[i + 1].getName())
            {
                pos = i + 1;
                break;
            }
        }
        for (int i = elementCount + 1; i > pos; --i)
            array[i] = array[i - 1];
        array[pos] = newPerson;
        elementCount++;
    //}
} // end add person

int SortedArray::binarySearch(int first, int last, Person target)
{
    int index = 0;
    if (first > last)
        index = -1;   //target not in array
    else
    {
        int mid = first + (last - first) / 2;
        if (target == array[mid])
            index = mid;
        else if (target < array[mid])
            index = binarySearch(first, mid - 1, target);
        else
            index = binarySearch(first, mid + 1,  target);
    } // end if
    return index;
} // end binarySearch

void SortedArray::printPerson(int index) const
{
    std::cout << std::left << std::setw(10) << array[index].getName() << '\t';
    std::cout << std::left << std::setw(10) << array[index].getMonth() << '\t';
    std::cout << array[index].getDate() << std::endl;
} // end printPerson

void SortedArray::printArray() const
{
    for (int index = 0; index < elementCount; index++)
        printPerson(index);
} // end printArray

void SortedArray::printMonth(std::string aMonth) const
{
    for (int index = 0; index < elementCount; index++)
    {
        if(array[index].getMonth() == aMonth)
            printPerson(index);
    } // end for
} //end printMonth

void SortedArray::remove(Person target)
{
    int index = binarySearch(0, elementCount - 1, target);
    for (;index < elementCount; index++)
        array[index] = array[index + 1];
    elementCount--;
}
