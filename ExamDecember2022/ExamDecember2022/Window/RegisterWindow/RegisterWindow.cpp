#include "RegisterWindow.h"
#include <iostream>

#pragma region constructor/destructor 
RegisterWindow::RegisterWindow(std::string _name, int _width, int _height, bool _save)
{
	name = _name;
	width = _width;
	height = _height;
	save = _save;

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
#pragma endregion constructor/destructor 
#pragma region methods



HWND RegisterWindow::WindowCreation(std::string _name, HINSTANCE _hinstance, HWND _hwnd, int CmdShow, MSG _uMsg)
{
	std::wstring Wname = std::wstring(name.begin(), name.end());
	HWND hwnd = CreateWindowEx(
		0,
		Wname.c_str(),
		Wname.c_str(),
		WS_OVERLAPPEDWINDOW,

		0, 0, width, height,

		NULL,       //parent window
		NULL,       //Menu
		_hinstance,
		NULL
	);

	if (hwnd == NULL)
	{
		return 0;
	}


	ShowWindow(hwnd, CmdShow);

	HDC hdc;
	PAINTSTRUCT ps;

	hdc = BeginPaint(hwnd, &ps);

	TextOut(hdc, 500, 0, L"Create New Booking", ARRAYSIZE(L"Create New Booking"));

	TextOut(hdc, 0, 100, L"Enter first name:", ARRAYSIZE(L"Enter first name:"));
	WindowMenu::CreateTextBox("", hwnd, 100, 150, 200);
	TextOut(hdc, 0, 150, L"Enter last name:", ARRAYSIZE(L"Enter last name:"));
	WindowMenu::CreateTextBox("", hwnd, 150, 150, 200);
	TextOut(hdc, 0, 200, L"For how many people: ", ARRAYSIZE(L"For how many people: "));
	WindowMenu::CreateTextBox("", hwnd, 200, 200, 100);
	WindowMenu::CreateCalendar("Calendar", hwnd, 300, 10, 100);
	WindowMenu::CreateButton("Return", hwnd, 0, 0, 70,3);
	WindowMenu::CreateButton("Save Bookings", hwnd, 500, 30, 120,4);

	if (save == true)
	{
		TextOut(hdc, 500, 30, L"Successful booking", ARRAYSIZE(L"Successful booking"));
	}

	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}
#pragma endregion methods
