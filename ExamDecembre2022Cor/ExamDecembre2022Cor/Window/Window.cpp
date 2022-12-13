#include "Window.h"
#include "Menu/BaseMenu.h"
#include "Control/TextField/TextFieldControl.h"
#include "Control/Calendar/CalendarControl.h"
#include <format>
#include <ranges>

#pragma region constructor/destructor
Window::Window(const wchar_t* _title, int _width, int _height)
{
	title = _title;
	width = _width;
	height = _height;

	INITCOMMONCONTROLSEX _iccex;
	_iccex.dwSize = sizeof(_iccex); 
	_iccex.dwICC = ICC_DATE_CLASSES; 

	if (!InitCommonControlsEx(&_iccex))
	{
		throw std::exception("[Window] => failed to initialize common controls !"); 
	}

	hInstance = GetModuleHandle(NULL); 
	LPCWSTR _className = TEXT("Sample Window Class");
	WNDCLASS _wndClass = {}; 
	_wndClass.style = CS_HREDRAW | CS_VREDRAW; 
	_wndClass.hbrBackground = (HBRUSH)COLOR_WINDOW; 
	_wndClass.lpszClassName = _className;
	_wndClass.hInstance = hInstance; 
	_wndClass.lpfnWndProc = WindowProcInternal;
	RegisterClass(&_wndClass); 

	windowInstance = CreateWindowEx(WS_EX_APPWINDOW, _className, title, WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT, CW_USEDEFAULT, width, height, nullptr, nullptr, hInstance, this); 

	std::wstring _wstr = title;
	std::string _titleCstr(_wstr.begin(), _wstr.end()); 
	SetWindowTextA(windowInstance, _titleCstr.c_str());

}

Window::~Window()
{
	for (BaseMenu* menu : menus | std::ranges::views::values)
		delete menu;
	menus.clear();
	if (isOpen)
		Close(); 
}


#pragma endregion constructor/destructor
#pragma region Proc
LRESULT _stdcall Window::WindowProcInternal(HWND _hwindow, UINT _msg, WPARAM _wp, LPARAM _lp)
{
	if (_msg == WM_NCCREATE)
	{
		SetWindowLongPtr(_hwindow, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(reinterpret_cast<CREATESTRUCT*>(_lp)->lpCreateParams));
		return true;
	}
	return reinterpret_cast<Window*>(GetWindowLongPtr(_hwindow, GWLP_USERDATA))->WindowProc(_hwindow, _msg, _wp, _lp); 
}
LRESULT _stdcall Window::WindowProc(HWND _hwindow, UINT _msg, WPARAM _wp, LPARAM _lp)
{
	if (_hwindow == nullptr) return false; 
	switch (_msg)
	{
	case WM_COMMAND :
	{
		if (ButtonControl::buttons.contains(_wp))
		{
			ButtonControl::buttons[_wp]->OnUse();
			break;

		}
		WORD _word = HIWORD(_wp); 
		switch (_word)
		{
		case EN_CHANGE:
		{
			std::map<int, TextFieldControl*> textfields = TextFieldControl::textfields;
			for (std::pair<int, TextFieldControl*> _pair : textfields)
			{
				if (_pair.first == LOWORD(_wp))
				{
					_pair.second->OnValueChange();
					break;
				}
			}
			break;
		}
		}
		break;
	}
	case WM_NOTIFY :
	{
		LPNMHDR _lpm = (LPNMHDR)_lp;
		switch (_lpm->code)
		{
		case MCN_SELECT: 
		{
			std::map<int, CalendarControl*> _calendars = CalendarControl::calendars;
			for (std::pair<int, CalendarControl*> _pair : _calendars)
			{
				if (_pair.first == _wp)
				{
					_pair.second->OnChoice((LPNMSELCHANGE)_lp);
					break;
				}
			}
			break;
		}
		}
		break;
	}
	case WM_DESTROY :
	{
		isOpen = false;
		exit(0);
		break;
	}
	}
	return DefWindowProc(_hwindow, _msg, _wp, _lp); 
}
#pragma endregion Proc
#pragma region methods
void Window::RegisterMenu(BaseMenu* _menu)
{
	if (menus.contains(_menu->Name())) return; 
	if (!_menu->IsInitialized())
		_menu->Initialize();
	menus.insert(std::pair(_menu->Name(), _menu));
}
void Window::SetCurrentMenu(const char* _menuName)
{
	if (!menus.contains(_menuName))
		throw std::exception(std::format("[Window] => {} doesn't exist", _menuName).c_str()); 
	if (currentMenu != nullptr) 
		currentMenu->Close();
	currentMenu = menus[_menuName];
	currentMenu->Open(); 
}
void Window::Open()
{
	if(windowInstance == nullptr)
		throw std::exception("[Window] => window instance is null !");
	ShowWindow(windowInstance, SW_NORMAL); 
	UpdateWindow(windowInstance); 
	isOpen = true; 
	Update(); 
}
void Window::Close()
{
	if (windowInstance == nullptr || !isOpen)
		throw std::exception("[Window] => window instance is null or not open, failed to close window!");
	isOpen = false; 
}
void Window::Update()
{
	MSG msg = {}; 
	while (isOpen)
	{
		try
		{
			while (PeekMessage(&msg, windowInstance, 0, 0, PM_REMOVE))
			{
				if (!TranslateAccelerator(msg.hwnd, nullptr, &msg))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}

			}
		}
		catch (const std::exception& _e)
		{
			std::cout << _e.what() << std::endl; 
		}
	}
}
int Window::Width()
{
	return width;
}
HWND Window::WindowInstance() const
{
	return windowInstance; 
}
#pragma endregion methods