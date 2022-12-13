#pragma once
#include "../WindowControl.h"
#include "../../../Event/Delegate/Delegate.h"
#include <map>


class ButtonControl : public WindowControl
{
	DECLARE_CLASS_INFO(WindowControl);

#pragma region f/p
public: 
	static inline std::map<int, ButtonControl*> buttons = std::map<int, ButtonControl*>(); 
	Delegate<void> OnClick = nullptr; 
private: 
	const wchar_t* text = TEXT("Default"); 
#pragma endregion f/p
#pragma region constructor
public: 
	ButtonControl() = default; 
	ButtonControl(int _controlID, HWND _owner,const Rect& _rect, const wchar_t* _text); 
	ButtonControl(const ButtonControl& _copy); 
#pragma endregion constructor
#pragma region methods
public: 
	virtual void OnUse();
#pragma endregion methods
#pragma region override
public: 
	virtual HWND Create(); 
#pragma endregion override
};

