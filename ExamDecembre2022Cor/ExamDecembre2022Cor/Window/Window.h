#pragma once
#include "../Object/Object.h"
#include <windows.h>
#pragma comment(lib, "Comctl32.lib")
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#include <CommCtrl.h>
#include "Control/Button/ButtonControl.h"
#include <iostream>
#include <map>


class BaseMenu;

class Window : public Object
{
	DECLARE_CLASS_INFO(Object); 
#pragma region f/p
private: 
	HWND windowInstance = nullptr;
	HINSTANCE hInstance = HINSTANCE();
	const wchar_t* title = TEXT("Default Window");
	int width = 1920;
	int height = 1080;
	bool isOpen = false; 
	std::map<std::string, BaseMenu*> menus = std::map<std::string, BaseMenu*>();
	BaseMenu* currentMenu = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
	public: 
		Window() = default; 
		Window(const wchar_t* _title, int _width = 1920, int _height = 1080);
		~Window() override; 
#pragma enderegion constructor/destructor
#pragma region Proc
		static LRESULT _stdcall WindowProcInternal(HWND _hwindow, UINT _msg, WPARAM _wp, LPARAM _lp);
		LRESULT _stdcall WindowProc(HWND _hwindow, UINT _msg, WPARAM _wp, LPARAM _lp);
#pragma endregion Proc
#pragma region methods
public: 
	void RegisterMenu(BaseMenu* _menu);
	void SetCurrentMenu(const char* _menuName);
	void Open(); 
	void Close(); 
	void Update();
	int Width();
	HWND WindowInstance() const; 
#pragma endregion methods
};

