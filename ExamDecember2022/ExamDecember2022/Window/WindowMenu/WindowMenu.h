#pragma once
#include "../../Object/Object.h"
#include <Windows.h>


class WindowMenu : public Object
{
#pragma region f/p
private: 
	HWND hwnd = HWND();
	HMENU menu = HMENU();
	std::string name = "";

#pragma endregion f/p
#pragma region constructor/destructor 
public:
	WindowMenu(HWND _hwnd, std::string _name);
#pragma endregion constructor/destructor 
#pragma region methods
public:
	static HWND CreateCalendar(std::string _name, HWND _parentWindow, int _y, int _x, int _size);
	static HWND CreateTextBox(std::string _name, HWND _parentWindow, int _y, int _x, int _size);
	static HWND CreateButton(std::string _name, HWND _parentWindow, int _y, int _x, int _size);
#pragma endregion methods
#pragma region override

#pragma endregion override
};

