#pragma once
#include "../BaseMenu.h"

class LabelControl;
class CalendarControl;

class BookingViewDataMenu : public BaseMenu
{
	DECLARE_CLASS_INFO(BaseMenu)
#pragma region f/p
private: 
	LabelControl* firstName = nullptr; 
	LabelControl* lastName = nullptr;
	LabelControl* numberOfPeople = nullptr;
	CalendarControl* calendar = nullptr;
#pragma endregion f/p
#pragma region contructor
public: 
	BookingViewDataMenu() = default; 
	BookingViewDataMenu(Window* _owner); 
	BookingViewDataMenu(const BookingViewDataMenu& _copy) = default; 
#pragma endregion contructor
#pragma region methods
private:
	void Delete(); 
	void ReturnToBookingView(); 
#pragma endregion methods
#pragma region override
public: 
	void Initialize() override; 
	void Open() override; 
#pragma endregion override
};

