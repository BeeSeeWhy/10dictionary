#ifndef ENTRY_
#define ENTRY_

template <class KeyType, class ValueType>
class Entry
{
private:
    KeyType key;
    ValueType value;

protected:
    void setKey(const KeyType& searchKey);

public:
    Entry();
    Entry(const KeyType& searchKey, const ValueType& newValue);
    ValueType getValue() const
        { return value; }
    void setValue(const ValueType& newValue)
        { value = newValue; }

    bool operator==(const Entry<KeyType, ValueType>& rightHandValue) const;
    bool operator>(const Entry<KeyType, ValueType>& rightHandValue) const;
}; // end Entry
#endif
