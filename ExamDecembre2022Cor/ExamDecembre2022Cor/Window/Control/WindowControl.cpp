#include "WindowControl.h"

#pragma region constructor/destructor
WindowControl::WindowControl(int _controlID, HWND _owner, const Rect& _rect) : super()
{
	controlID = _controlID; 
	owner = _owner; 
	rect = _rect;
	ownerInstance = (HINSTANCE)GetWindowLongPtr(owner, GWLP_HINSTANCE); 
}

WindowControl::WindowControl(const WindowControl& _copy) : super(_copy)
{
	controlID = _copy.controlID;
	owner = _copy.owner;
	ownerInstance = _copy.ownerInstance;
	rect = _copy.rect;
}

#pragma endregion constructor/destructor
#pragma region methods
void WindowControl::Show()
{
	if (!isInitialized) return; 
	ShowWindow(instance, true); 
	isShow = true; 
}
void WindowControl::Hide()
{
	if (!isInitialized) return;
	ShowWindow(instance, false);
	isShow = false;
}
bool WindowControl::IsInitialized() const
{
	return isInitialized;
}
HWND WindowControl::Create()
{
	return (HWND)NULL; 
}
#pragma endregion methods