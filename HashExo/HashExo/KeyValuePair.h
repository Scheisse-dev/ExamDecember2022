#pragma once
#include "Object.h"

template <typename TValue>
class KeyValuePair
{
#pragma region f/p
	int key = 0;
	TValue value;
#pragma endregion f/p
#pragma region constructor
public:
	KeyValuePair() = default; 
	KeyValuePair(TValue _value)
	{
		key = Object::hachage(_value);
		value = _value;
	
	}
	KeyValuePair(const KeyValuePair& _copy)
	{
		key = _copy.key;
		value = _copy.value; 
	}
#pragma endregion constructor
#pragma region methods
public:
	int Key() const;
	TValue Value() const;
#pragma endregion methods
};

template<typename TValue>
inline int KeyValuePair<TValue>::Key() const
{
	return key;
}

template<typename TValue>
inline TValue KeyValuePair<TValue>::Value() const
{
	return value;
}
