#pragma once
#include "../WindowMenu/WindowMenu.h"
#include "../Window.h"
#include "../../Object/Object.h"
#include <Windows.h>

class DisplayWindow : public Window
{
#pragma region f/p
private:
	std::string name = "";
	std::wstring wName = std::wstring(name.begin(), name.end());
	MSG msg = MSG();
	HWND hwnd = HWND();
	int width = 0;
	int height = 0;
	int index = 0;
#pragma endregion f/p
#pragma region constructor
public:
	DisplayWindow() = default;
	DisplayWindow(std::string _name, int _width, int _height);
#pragma endregion constructor
#pragma region override
	HWND WindowCreation(std::string _name, HINSTANCE _hinstance, HWND _hwnd, int CmdShow, MSG _uMsg) override;
#pragma endregion override
};

