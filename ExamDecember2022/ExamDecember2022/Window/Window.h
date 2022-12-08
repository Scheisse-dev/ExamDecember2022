#pragma once
#include "../Object/Object.h"
#include <Windows.h>
#include <vector>

class Window 
{
#pragma region f/p
private: 
	std::string name = "";
	std::wstring wName = std::wstring(name.begin(), name.end());
	MSG msg = MSG();
	HWND hwnd = HWND();
	int width = 1280;
	int height = 1024;
#pragma endregion f/p
#pragma region constructor
public:
	Window() = default;
	Window(std::string _name, int _width, int height);
#pragma endregion constructor
#pragma region methods
public: 
	virtual HWND WindowCreation(std::string _name, HINSTANCE _hinstance, HWND _hwnd, int CmdShow, MSG _uMsg);
	virtual LRESULT WindowProc(HWND _hwnd, UINT _uMsg, WPARAM _wParam, LPARAM _lParam);
	static LRESULT CALLBACK WindowProc_Internal(HWND _hwnd, UINT _uMsg, WPARAM _wParam, LPARAM _lParam);
#pragma endregion methods
};
