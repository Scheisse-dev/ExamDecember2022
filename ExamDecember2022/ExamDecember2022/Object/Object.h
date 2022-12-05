#pragma once
#include <string>
class Object
{
#pragma region constructor/destructor 
public:
	Object() = default; 
	Object(const Object&) = default;
	~Object() = default; 
#pragma region constructor/destructor 
#pragma region methods
public:
	virtual std::string ToString(); 
#pragma endregion methods
};

