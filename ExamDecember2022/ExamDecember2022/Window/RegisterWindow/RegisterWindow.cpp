#include "RegisterWindow.h"

#pragma region constructor/destructor 
RegisterWindow::RegisterWindow(std::string _name, int _width, int _height)
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

void RegisterWindow::Close()
{
	//TODO
}

void RegisterWindow::Open()
{

	//TODO
}

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
	WindowMenu::CreateCalendar("PUTAIN", hwnd, 300, 10, 100);
	WindowMenu::CreateTextBox("PUTAIN", hwnd, 50, 50, 100); 
	WindowMenu::CreateButton("Return", hwnd, 0, 0, 70);
	WindowMenu::CreateButton("Save Bookings", hwnd, 500, 30, 120);


	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT RegisterWindow::WindowProc(HWND _hwnd, UINT _uMsg, WPARAM _wParam, LPARAM _lParam)
{
	if (_hwnd == nullptr) return -1;
	switch (_uMsg)
	{
	case WM_DESTROY:
		DestroyWindow(hwnd);
		break;
	}
	return DefWindowProc(_hwnd, _uMsg, _wParam, _lParam);
}


LRESULT RegisterWindow::WindowProc_Internal(HWND _hwnd, UINT _uMsg, WPARAM _wParam, LPARAM _lParam)
{
	return DefWindowProc(_hwnd, _uMsg, _wParam, _lParam);
}



#pragma endregion methods