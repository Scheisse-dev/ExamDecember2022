#pragma once
#include "../Object/Object.h"
#include "WindowMenu/WindowMenu.h"
#include <Windows.h>


class Window
{
#pragma region f/p
private:
	std::string name = ""; 
	MSG msg = MSG(); 
	HWND hwnd = HWND();
	int width =  1200;
	int height = 1000;
	bool isOpen = false; 
#pragma endregion f/p
#pragma region constructor/destructor 
public:
	Window() = default; 
	Window(std::string _name, int _width, int height);
#pragma endregion constructor/destructor 
#pragma region methods
public: 
	void Close(); 
	void Open();
	HWND WindowCreation(std::string _name, HINSTANCE _hinstance, HWND _hwnd, int CmdShow, MSG _uMsg); 
	LRESULT WindowProc(HWND _hwnd, UINT _uMsg, WPARAM _wParam, LPARAM _lParam);
	static LRESULT CALLBACK WindowProc_Internal(HWND _hwnd, UINT _uMsg, WPARAM _wParam, LPARAM _lParam);

#pragma endregion methods

};

