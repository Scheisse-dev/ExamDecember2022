#pragma once
#include "../WindowControl.h"

class LabelControl : public WindowControl
{
	DECLARE_CLASS_INFO(WindowControl);
#pragma region f/p
	const wchar_t* text = TEXT(""); 
#pragma endregionf/p
#pragma region constructor
	LabelControl() = default; 
	LabelControl(int _controlID, HWND _owner, Rect _rect, const wchar_t* _text); 
	LabelControl(const LabelControl& _copy);
#pragma endregion constructor
#pragma region methods
	std::string TextStr();
	std::wstring Text();
	void SetText(const wchar_t* _newtext);
	void SetText(const std::string& _str); 
#pragma endregion methods
#pragma region override
	HWND Create() override;
#pragma endregion override
};

