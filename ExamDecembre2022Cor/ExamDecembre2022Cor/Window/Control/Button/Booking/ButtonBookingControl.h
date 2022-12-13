#pragma once
#include "../ButtonControl.h"

class Booking;

class ButtonBookingControl : public ButtonControl
{
	DECLARE_CLASS_INFO(ButtonControl)

#pragma region f/p
public:
	Delegate<void, Booking*> OnClickBooking = nullptr; 
private: 
	Booking* booking = nullptr; 
#pragma endregion f/p
#pragma region constructor
public: 
	ButtonBookingControl() = default; 
	ButtonBookingControl(int _controlID, HWND _owner, const Rect& _rect, const wchar_t* _text, Booking* _booking);
	ButtonBookingControl(const ButtonBookingControl& _copy);
#pragma endregion constructor
#pragma region override
public:
	HWND Create() override; 
	void OnUse() override; 
#pragma endregion override
};

