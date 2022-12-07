#include "Window.h"
#include "WindowMenu/WindowMenu.h"
#include "StartWindow/StartWindow.h"
#include <iostream>

Window::Window(std::string _name, int _width, int _height)
{
	name = _name;
	width = _width;
	height = _height;

	HINSTANCE _instance = HINSTANCE();

	std::wstring wstr = std::wstring(name.begin(), name.end());
	WNDCLASS wc = {};
	wc.hInstance = _instance,
	wc.lpfnWndProc = WindowProc_Internal;
	wc.hCursor = LoadCursor(NULL, IDC_HAND);
	wc.lpszClassName = wstr.c_str();

	RegisterClass(&wc);

	WindowCreation(_name, _instance, hwnd, 1, msg);
}


void Window::Close()
{
	DestroyWindow(hwnd);
}

void Window::Open()
{

	isOpen = true;
}
HWND Window::WindowCreation(std::string _name, HINSTANCE _hinstance, HWND _hwnd, int CmdShow, MSG _uMsg)
{
	return 0;
}

LRESULT Window::WindowProc(HWND _hwnd, UINT _uMsg, WPARAM _wParam, LPARAM _lParam)
{
	if (_hwnd == nullptr) return -1;
	switch (_uMsg)
	{
	case WM_NOTIFY:
		std::cout << "coucou";

	case WM_DESTROY:
		DestroyWindow(hwnd);
		break;
	}
	return DefWindowProc(_hwnd, _uMsg, _wParam, _lParam);
}
LRESULT Window::WindowProc_Internal(HWND _hwnd, UINT _uMsg, WPARAM _wParam, LPARAM _lParam)
{
	if (_hwnd == nullptr) return -1;
	switch (_uMsg)
	{
		
	case  WM_COMMAND:
		
			StartWindow win = StartWindow("Hotel Application", 1080, 700);
	
	}
	return DefWindowProc(_hwnd, _uMsg, _wParam, _lParam);
}
