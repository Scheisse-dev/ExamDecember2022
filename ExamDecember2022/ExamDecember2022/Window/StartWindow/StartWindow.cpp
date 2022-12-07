#include "StartWindow.h"




#pragma region constructor/destructor 
StartWindow::StartWindow(std::string _name, int _width, int _height)
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
#pragma endregion constructor/destructor 
#pragma region methods

void StartWindow::Close()
{
	isOpen = false;
}

void StartWindow::Open()
{

	isOpen = true;
}

HWND StartWindow::WindowCreation(std::string _name, HINSTANCE _hinstance, HWND _hwnd, int CmdShow, MSG _uMsg)
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

	TextOut(hdc, 500, 0, L"Hotel Objectif3D", ARRAYSIZE(L"Hotel Objectif3D"));
	WindowMenu::CreateButton("Create new Booking", hwnd, 50, 50, 200);
	WindowMenu::CreateButton("View all Bookings", hwnd, 50, 300, 200);

	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}



#pragma endregion methods