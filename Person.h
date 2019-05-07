#ifndef _PERSON
#define _PERSON
#include <string>

class Person
{
private:
    std::string name;
    std::string month;
    int date;

public:
    Person()
        { name = ""; month = ""; date = 0;}
    Person(std::string& aName, const std::string aMonth, int aDate)
        { name = aName; month = aMonth; date = aDate; }
    std::string getName() const
        { return name; }
    std::string getMonth() const
        { return month; }
    int getDate() const
        { return date; }

    void setInfo(std::string aName, std::string aMonth, int aDate)
        { name = aName; month = aMonth, date = aDate; }
    void setName(std::string aName)
        { name = aName; }
    void setMonth(std::string aMonth)
        { month = aMonth; }
    void setDate(int aDate)
        { date = aDate; }

    bool operator< (Person& rightHandValue) const
        { return name < rightHandValue.getName(); }
    bool operator== (Person& rightHandValue) const
        { return name == rightHandValue.getName(); }
    bool operator> (Person& rightHandValue) const
        { return name == rightHandValue.getName();}
    bool operator<= (Person& rightHandValue) const
        { return name <= rightHandValue.getName(); }
}; // end Person
#endif
