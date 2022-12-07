#pragma once
#include <map>
#include <vector>
#include "../Object/Object.h"

#define Booking(name, ...) struct name (__VA_ARGS__)\
{\
 std::string firstName = varargs1(1);\
 std::string lastName;\
 int people;\
 std::string date;\
};\

class Reservation
{
#pragma region f/p 
private :
	std::string firstName, lastName , date = ""; 
	int people = 0; 
protected: 

#pragma endregion f/p 
#pragma region constructor/destructor
public:
	Reservation(std::string _firstName, std::string _lastName, int _people, std::string _date);
	Reservation(const Reservation& _copy);
	~Reservation(); 
#pragma endregion constructor/destructor
#pragma region methods
public:

#pragma endregion methods

};

