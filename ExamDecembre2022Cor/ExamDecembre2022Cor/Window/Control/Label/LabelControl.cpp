#include "LabelControl.h"

LabelControl::LabelControl(int _controlID, HWND _owner, Rect _rect, const wchar_t* _text) : super(_controlID, _owner, _rect)
{
    controlID = _controlID;
    owner = _owner; 
    rect = _rect; 
    text = _text;
}

LabelControl::LabelControl(const LabelControl& _copy) : super(_copy)
{
    controlID = _copy.controlID;
    owner = _copy.owner;
    rect = _copy.rect;
    text = _copy.text;
}

std::string LabelControl::TextStr()
{
    const std::wstring _text = Text(); 
    return std::string(_text.begin(), _text.end());
}

std::wstring LabelControl::Text()
{
    return text;
}

void LabelControl::SetText(const wchar_t* _newtext)
{
    text = _newtext;
    SetWindowTextA(instance, TextStr().c_str());
}

HWND LabelControl::Create()
{
    instance = CreateWindowEx(0, L"STATIC", text, WS_CHILD | WS_VISIBLE, rect.X(), rect.Y(), rect.Width(), rect.Height(),
        owner, (HMENU)controlID, ownerInstance, nullptr);
    if (instance != NULL)
    {
        L"TEST"; 
        isInitialized = true; 
        Show(); 

    }
    return instance; 
}
