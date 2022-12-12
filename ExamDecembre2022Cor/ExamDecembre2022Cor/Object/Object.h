#pragma once
#include <exception>
#include <string>

#define DECLARE_CLASS_INFO(parent) \
	public:\
		typedef parent super ;

class Object
{
#pragma region constructor/destructor
public:
	Object() = default;
	virtual ~Object() = default; 
#pragma endregion constructor/destructor
#pragma region methods
public:
	virtual std::string ToString() const; 
#pragma endregion methods
};

