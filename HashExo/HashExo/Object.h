#pragma once
#include <string>

class Object
{
public: 
	Object() = default;
	~Object() = default; 

public:
	std::string ToString()
	{
		return ""; 
	}

	static int hachage(std::string str)
	{
		int i = 0, _hash = 0;

		for (i = 0; str[i] != '\0'; i++)
		{
			_hash += str[i];
		}
		_hash %= 100;

		return _hash;
	};
};

