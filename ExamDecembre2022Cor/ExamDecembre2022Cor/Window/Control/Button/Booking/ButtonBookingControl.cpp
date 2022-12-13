#include "ButtonBookingControl.h"


#pragma region constructor
ButtonBookingControl::ButtonBookingControl(int _controlID, HWND _owner, const Rect& _rect, const wchar_t* _text, Booking* _booking)
	: super(_controlID, _owner, _rect, _text)
{
	booking = _booking; 
}

ButtonBookingControl::ButtonBookingControl(const ButtonBookingControl& _copy) : super(_copy)
{
	booking = _copy.booking;
}
#pragma endregion constructor
#pragma region override
HWND ButtonBookingControl::Create()
{
	return super::Create(); 
}
void ButtonBookingControl::OnUse()
{
	OnClickBooking.Invoke(booking); 
	super::OnUse(); 
}
#pragma endregion override