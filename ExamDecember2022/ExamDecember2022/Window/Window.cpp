#include "Window.h"


#pragma region constructor/destructor 
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
#pragma endregion constructor/destructor 
#pragma region methods

void Window::Close()
{
	isOpen = false; 
}

void Window::Open()
{

	isOpen = true; 
}

HWND Window::WindowCreation(std::string _name, HINSTANCE _hinstance, HWND _hwnd, int CmdShow, MSG _uMsg)
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
	WindowMenu::CreateButton("Create new Booking" , hwnd , 50, 50);
	WindowMenu::CreateButton("View all Bookings", hwnd, 50, 300);
	WindowMenu::CreateButton("I wanna die !", hwnd, 100, 300);
	


	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT Window::WindowProc(HWND _hwnd, UINT _uMsg, WPARAM _wParam, LPARAM _lParam)
{
	if (_hwnd == nullptr) return -1; 
	switch (_uMsg)
	{
	case WM_CREATE:
	{
		CreateMenu();
		break;
	}
	case WM_DESTROY:
		DestroyWindow(hwnd);
		break;
	}
	return DefWindowProc(_hwnd, _uMsg, _wParam, _lParam);
}


LRESULT Window::WindowProc_Internal(HWND _hwnd, UINT _uMsg, WPARAM _wParam, LPARAM _lParam)
{
	return DefWindowProc(_hwnd, _uMsg, _wParam, _lParam);
}



#pragma endregion methods

