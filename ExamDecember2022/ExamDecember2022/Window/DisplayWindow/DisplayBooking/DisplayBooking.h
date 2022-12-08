#pragma once
#include "../../WindowMenu/WindowMenu.h"
#include "../../Window.h"
#include "../../Object/Object.h"
#include <Windows.h>

class DisplayBooking : public Window
{
private:
	std::string name = "";
	std::wstring wName = std::wstring(name.begin(), name.end());
	MSG msg = MSG();
	HWND hwnd = HWND();
	int width = 0;
	int height = 0;
public:
	DisplayBooking() = default;
	DisplayBooking(std::string _name, int _width, int _height);

public:
	HWND WindowCreation(std::string _name, HINSTANCE _hinstance, HWND _hwnd, int CmdShow, MSG _uMsg) override;
};

