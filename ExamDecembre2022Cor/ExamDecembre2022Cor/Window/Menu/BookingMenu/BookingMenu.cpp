#include "BookingMenu.h"
#include "../../../Utils/DataBase/MenuDataBase.h"
#include "../../Control/Calendar/CalendarControl.h"

#pragma region constructor
BookingMenu::BookingMenu(Window* _owner) : super(_owner, BOOKINGMENU)
{
}
#pragma endregion constructor
#pragma region override
void BookingMenu::Initialize()
{
	super::Initialize(); 
	CreateTextField(Rect(10, 50, 255, 20), L"first name...");
	CreateTextField(Rect(10, 80, 255, 20), L"last name...");
	CreateTextField(Rect(10, 110, 255, 20), L"number of people...");
	CreateButton(Rect(60, 350, 150, 20), L"Save Booking");
	CalendarControl* _calendar = CreateCalendar(Rect(10, 140, 150, 150)); 
	_calendar->SetMaxSelected(15);
	isInitialized = true;
	Close();

}
#pragma endregion override