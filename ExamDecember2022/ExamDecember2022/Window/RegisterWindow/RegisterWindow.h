#pragma once
#include "../WindowMenu/WindowMenu.h"
#include "../Window.h"
#include "../../Object/Object.h"
#include <Windows.h>

class RegisterWindow : public Window
{
#pragma region f/p
private:
	std::string name = "";
	std::wstring wName = std::wstring(name.begin(), name.end());
	MSG msg = MSG();
	HWND hwnd = HWND();
	int width = 0;
	int height = 0;
	bool save = false;
#pragma endregion f/p
#pragma region constructor/destructor 
public:
	RegisterWindow() = default;
	RegisterWindow(std::string _name, int _width, int _height, bool save);
#pragma endregion constructor/destructor 
#pragma region methods
public:
	HWND WindowCreation(std::string _name, HINSTANCE _hinstance, HWND _hwnd, int CmdShow, MSG _uMsg) override;
};

