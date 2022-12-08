#include "DisplayBooking.h"

DisplayBooking::DisplayBooking(std::string _name, int _width, int _height)
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

HWND DisplayBooking::WindowCreation(std::string _name, HINSTANCE _hinstance, HWND _hwnd, int CmdShow, MSG _uMsg)
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

	TextOut(hdc, 500, 0, L"Name", ARRAYSIZE(L"Name"));


	WindowMenu::CreateButton("Return", hwnd, 0, 0, 70, 3);
	TextOut(hdc, 0, 100, L"First name:", ARRAYSIZE(L"First name:"));
	TextOut(hdc, 0, 150, L"Last name:", ARRAYSIZE(L"Last name:"));
	TextOut(hdc, 0, 200, L"People: ", ARRAYSIZE(L"People: "));
	WindowMenu::CreateCalendar("Calendar", hwnd, 300, 10, 100);
	WindowMenu::CreateButton("Delete", hwnd, 500, 30, 120, 4);


	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}
