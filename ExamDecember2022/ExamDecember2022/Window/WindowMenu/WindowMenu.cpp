#include "WindowMenu.h"
#pragma comment(lib, "Comctl32.lib")
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#include <CommCtrl.h>
#include <windowsx.h>

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


HWND WindowMenu::CreateCalendar(std::string _name, HWND _parentWindow, int _y, int _x, int _size)
{    
    HWND calendar = CreateWindowEx(
        0,
        MONTHCAL_CLASS,
        L"",

        WS_BORDER | WS_CHILD | WS_VISIBLE | MCS_NOTODAY | MCS_MULTISELECT,
        _x, _y, 230, 150,
        _parentWindow,
        (HMENU)IDC_MONTHCAL,
        NULL,
        NULL);

    MonthCal_SetMaxSelCount(calendar, 30);

    _SYSTEMTIME sy[1] = {};

    MonthCal_GetToday(calendar, sy);
    MonthCal_SetRange(calendar, GDTR_MIN, sy);
    
    return calendar;
}

HWND WindowMenu::CreateTextBox(std::string _name, HWND _parentWindow, int _y, int _x, int _size)
{


    std::wstring wName = std::wstring(_name.begin(), _name.end());   
    HWND txt = CreateWindowEx(
        0L,
        L"Edit", 
        wName.c_str(), 

        WS_CHILD | WS_VISIBLE | WS_BORDER,
        _x, _y, _size, 20,
        _parentWindow, 
        NULL, 
        NULL, 
        NULL
    );

    

    return txt;
}


HWND WindowMenu::CreateButton(std::string _name, HWND _parentWindow, int _y, int _x, int _size, int _id)
{

    std::wstring wName = std::wstring(_name.begin(), _name.end());

    HWND button = CreateWindow(
        L"BUTTON",
        wName.c_str(),
        WS_BORDER | WS_VISIBLE | WS_CHILD ,
        _x,
        _y,
        _size,
        20,
        _parentWindow,
        NULL,
        (HINSTANCE)GetWindowLongPtr(_parentWindow, GWLP_HINSTANCE),
        NULL);

    SetWindowLongPtr(button, GWLP_ID, _id);
        return button;
        
}


#pragma endregion methods




