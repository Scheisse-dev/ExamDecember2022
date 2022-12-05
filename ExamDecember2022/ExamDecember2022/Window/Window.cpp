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
		L"Learn to Program Windows",    
		WS_OVERLAPPEDWINDOW,            

		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

		NULL,       
		NULL,       
		_hinstance,  
		NULL        
	);

	if (hwnd == NULL)
	{
		return 0;
	}

	ShowWindow(hwnd, CmdShow);


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
		//TODO menu
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(_hwnd, &ps);
		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

		EndPaint(hwnd, &ps);
	}
		break;
	case WM_DESTROY:
		Close(); 
		break;
	}
	return DefWindowProc(_hwnd, _uMsg, _wParam, _lParam);
}


LRESULT Window::WindowProc_Internal(HWND _hwnd, UINT _uMsg, WPARAM _wParam, LPARAM _lParam)
{
	return DefWindowProc(_hwnd, _uMsg, _wParam, _lParam);
}



#pragma endregion methods

