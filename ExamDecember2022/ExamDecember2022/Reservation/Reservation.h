#pragma once
#include <map>
#include <vector>
#include "../Object/Object.h"

//#define WindowMake(name, ...)\
//std::wstring wName = std::wstring(name.begin(), name.end());\
//HWND name = CreateWindowEx(\
//	0,\
//	Wname.c_str(),\
//	Wname.c_str(),\
//	WS_OVERLAPPEDWINDOW,\
//\
//	0, 0, width, height,\
//\
//	NULL,       \
//	NULL,       \
//	_hinstance,\
//	NULL\
//);\

class Reservation
{
#pragma region f/p 
private :
	std::string firstName, lastName , date = ""; 
	int people = 0; 
	/*std::vector<HWND> window = std::vector<HWND>(); */
protected: 

#pragma endregion f/p 
#pragma region constructor/destructor
public:
	Reservation() = default;
	Reservation(std::string _firstName, std::string _lastName, int _people, std::string _date);
	Reservation(const Reservation& _copy);
	~Reservation(); 
#pragma endregion constructor/destructor
#pragma region methods
public:
	static void ReservationRegister(); 
#pragma endregion methods

};

