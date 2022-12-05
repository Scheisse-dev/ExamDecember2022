#include "WindowMenu.h"

#pragma region constructor/destructor 
WindowMenu::WindowMenu(HWND _hwnd, std::string _name)
{
	hwnd = _hwnd;
	name = _name;
	menu = CreateMenu(); 
}

#pragma endregion constructor/destructor 
#pragma region methods
HWND WindowMenu::CreateButton(std::string _name, HWND _parentWindow, int _y, int _x)
{
    int size = _name.size()*7.5; 
    std::wstring wName = std::wstring(_name.begin(), _name.end());
    
    HWND button = CreateWindow(
        L"BUTTON", 
        wName.c_str(),   
        WS_EX_CLIENTEDGE | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        _x,         
        _y,         
        size,        
        20,        
        _parentWindow,     
        NULL,       
        (HINSTANCE)GetWindowLongPtr(_parentWindow, GWLP_HINSTANCE),
        NULL);
    return button; 
    
}


#pragma endregion methods
#pragma region override

#pragma endregion override


