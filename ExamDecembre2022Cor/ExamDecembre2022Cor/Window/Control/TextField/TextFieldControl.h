#pragma once
#include "../WindowControl.h"
#include <map>

class TextFieldControl : public WindowControl
{
	DECLARE_CLASS_INFO(WindowControl); 
#pragma region f/p
public: 
	static inline std::map<int,TextFieldControl*> textfields = std::map<int, TextFieldControl*>();
private:
	const wchar_t* defaultText = TEXT("");
	std::wstring currentText = TEXT(""); 
#pragma endregion f/p
#pragma endregion constructor
public:
	TextFieldControl() = default;
	TextFieldControl(int _controlID, HWND _owner, Rect _rect, const wchar_t* _defaultText);
	TextFieldControl(const TextFieldControl& _copy);
#pragma region constructor
#pragma region methods
public:
	void OnValueChange();
	std::wstring CurrentText() const; 
	std::string CurrentTextStr() const;
	void OnTextChange(const wchar_t* _text);
	HWND Create() override; 
#pragma endregion methods
};

