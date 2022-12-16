#pragma once
#include <initializer_list>
#include <exception>
#include "KeyValuePair.h"


template <typename Tvalue>
class Map
{
#pragma region f/p
private:
	KeyValuePair<Tvalue>* tab = new KeyValuePair<Tvalue>[0];
	int count = 0;

#pragma endregion f/p
#pragma region typedef
public:
	typedef KeyValuePair<Tvalue>* iterator;
	typedef const KeyValuePair<Tvalue>* const_iterator;

	iterator begin()
	{
		return &tab[0];
	}
	const_iterator begin() const
	{
		return &tab[0];
	}
	iterator end()
	{
		return &tab[count];
	}
	const_iterator end() const
	{
		return &tab[count];
	}
#pragma endregion typedef
#pragma region constructor/destructor
public:
	Map() = default;
	Map(std::initializer_list<KeyValuePair<Tvalue>> _tab)
	{
			for (KeyValuePair<Tvalue> _pair : _tab)
				Insert(_pair);

	}
	Map(const Map& _copy)
	{
		tab = _copy.tab;
		count = _copy.count;
	}
	~Map()
	{
		delete[] tab;
		count = 0;
		tab = new KeyValuePair<Tvalue>[0];
	}

#pragma endregion constructor/destructor
#pragma region methods
private:
	int IndexOfKey(int _key) const;
public:
	void Insert(const Tvalue& _value);
	void Insert(KeyValuePair<Tvalue> _pair);
	void Clear();
	void Remove(int _key);
	bool IsEmpty() const;
	bool Contains(int _key);
	Tvalue At(int _key);
	//int GetKey(const Tvalue& _value );

#pragma endregion methods
#pragma region operator
public:
	Tvalue& operator[] (int _key);

#pragma endregion operator
};





template<typename Tvalue>
inline int Map<Tvalue>::IndexOfKey(int _key) const
{
	for (int i = 0; i < count; i++)
	{
		if (tab[i].Key() == _key)
			return i;
	}
	return -1;
}

template<typename Tvalue>
inline void Map<Tvalue>::Insert(const Tvalue& _value)
{
	Insert(KeyValuePair<Tvalue>(_value));
}

template<typename Tvalue>
inline void Map<Tvalue>::Insert(KeyValuePair<Tvalue> _pair)
{
	KeyValuePair<Tvalue>* _tmp = tab;
	tab = new KeyValuePair<Tvalue>[count + 1];
	for (int i = 0; i < count; i++)
		tab[i] = _tmp[i];
	tab[count] = _pair;
	count++;
}

template<typename Tvalue>
inline void Map<Tvalue>::Clear()
{
	delete[] tab;
	count = 0;
	tab = new KeyValuePair<Tvalue>[0];
}

template<typename Tvalue>
inline void Map<Tvalue>::Remove(int _key)
{

	const int _index = IndexOfKey(_key);
	if (_index == -1) throw std::exception("key doesn't exist ! ");
	KeyValuePair<Tvalue>* _tmp = tab;
	tab = new KeyValuePair<Tvalue>[count - 1];
	for (int i = 0; i < _index; i++)
		tab[i] = _tmp[i];
	for (int i = 0; i < _index; i++)
		tab[i - 1] = _tmp[i];
	count--;
}

template<typename Tvalue>
inline bool Map<Tvalue>::IsEmpty() const
{
	return count == 0;
}

template<typename Tvalue>
inline bool Map<Tvalue>::Contains(int _key)
{
	return IndexOfKey(_key) != -1;
}

template<typename Tvalue>
inline Tvalue Map<Tvalue>::At(int _key)
{
	
	const int _index = IndexOfKey(_key);
	if (_index == -1) throw std::exception("key doesn't exist");
	return tab[_index].Value();
}

//template<typename Tvalue>
//inline int Map<Tvalue>::GetKey(const Tvalue& _value)
//{
//	return 0;
//}

template<typename Tvalue>
inline Tvalue& Map<Tvalue>::operator[](int _key)
{
	return At(_key);
}
