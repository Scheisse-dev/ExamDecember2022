#include "WindowMenu.h"
#pragma comment(lib, "Comctl32.lib")
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#include <CommCtrl.h>

#define IDC_MONTHCAL 101



#pragma region constructor/destructor 
WindowMenu::WindowMenu(HWND _hwnd, std::string _name)
{
    hwnd = _hwnd;
    name = _name;
    menu = CreateMenu();
}

#pragma endregion constructor/destructor 
#pragma region methods

LRESULT WindowProc(HWND _hwnd, UINT _uMsg, WPARAM _wParam, LPARAM _lParam)
{
    if (_hwnd == nullptr) return -1;
    switch (_uMsg)
    {
    case WM_DESTROY:
        DestroyWindow(_hwnd);
        break;
    }
    return DefWindowProc(_hwnd, _uMsg, _wParam, _lParam);
}



HWND WindowMenu::CreateCalendar(std::string _name, HWND _parentWindow, int _y, int _x, int _size)
{    
    HWND txt = CreateWindowEx(
        0,
        MONTHCAL_CLASS,
        L"",

        WS_BORDER | WS_CHILD | WS_VISIBLE | MCS_NOTODAY ,
        _x, _y, 230, 150,
        _parentWindow,
        (HMENU)IDC_MONTHCAL,
        NULL,
        NULL);


    
    return txt;
}

HWND WindowMenu::CreateTextBox(std::string _name, HWND _parentWindow, int _y, int _x, int _size)
{
    std::wstring wName = std::wstring(_name.begin(), _name.end());
    HWND txt = CreateWindowEx(
        0L, 
        L"Edit", 
        wName.c_str(), 

        MCS_NOTODAY | WS_CHILD | WS_VISIBLE | WS_BORDER,
        _x, _y, _size, 20, 
        _parentWindow, 
        NULL, 
        NULL, 
        NULL);

    _SYSTEMTIME sy = {2022, 12};
    

    return txt;
}

HWND WindowMenu::CreateButton(std::string _name, HWND _parentWindow, int _y, int _x, int _size)
{

    std::wstring wName = std::wstring(_name.begin(), _name.end());

    HWND button = CreateWindow(
        L"BUTTON",
        wName.c_str(),
        WS_BORDER | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        _x,
        _y,
        _size,
        20,
        _parentWindow,
        NULL,
        (HINSTANCE)GetWindowLongPtr(_parentWindow, GWLP_HINSTANCE),
        NULL);
    return button;

}


#pragma endregion methods




