#include "Entry.h"

// protected
template <class KeyType, class ValueType>
void Entry<KeyType, ValueType>::setKey(const KeyType& searchKey)
{
    key = searchKey;
} // end setKey

//public:
template <class KeyType, class ValueType>
Entry<KeyType, ValueType>::Entry()
{
}

template <class KeyType, class ValueType>
Entry<KeyType, ValueType>::Entry(const KeyType& searchKey,
                                const ValueType& newValue)
{
    key = searchKey;
    value = newValue;
} // end constructor


template <class KeyType, class ValueType>
bool Entry<KeyType, ValueType>::operator==(const Entry<KeyType,
                                ValueType>& rightHandValue) const
{
    return (searchKey == rightHandValue.getKey());
} // end operator ==

template <class KeyType, class ValueType>
bool Entry<KeyType, ValueType>::operator>(const Entry<KeyType,
                                ValueType>& rightHandValue) const
{
    return (searchKey > rightHandValue.getKey());
} // end operator >
