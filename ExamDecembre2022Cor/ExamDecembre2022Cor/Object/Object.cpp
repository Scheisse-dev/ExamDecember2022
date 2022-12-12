#include "Object.h"
#include <typeinfo>

#pragma region methods
std::string Object::ToString() const
{
	std::string _name = typeid(*this).name(); 
	return _name.substr(_name.find_last_of(' ') + 1);
}
#pragma endregion methods