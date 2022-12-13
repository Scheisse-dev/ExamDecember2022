#include "BookingViewDataMenu.h"
#include "../../../Utils/DataBase/MenuDataBase.h"
#include "../BookingViewMenu/BookingViewMenu.h"
#include "../../../Booking/Manager/BookingManager.h"
#include "../../../Booking/Client/Client.h"
#include "../../../Booking/Booking.h"
#include "../../../Window/Window.h"
#include "../../Control/Calendar/CalendarControl.h"

#pragma region contructor
BookingViewDataMenu::BookingViewDataMenu(Window* _owner) : super(_owner , BOOKINGVIEWDATA)
{}
#pragma endregion contructor
#pragma region methods
void BookingViewDataMenu::Delete()
{
	BookingManager::Instance()->DeleteBoooking(BookingViewMenu::CurrentBooking);
	ReturnToBookingView();
}

void BookingViewDataMenu::ReturnToBookingView()
{
	owner->SetCurrentMenu(BOOKINGVIEWMENU);
}
#pragma endregion methods
#pragma region override
void BookingViewDataMenu::Initialize()
{
	super::Initialize(); 
	ButtonControl* _returnControl = CreateButton(Rect(10, 0, 100, 20), TEXT("Return"));
	_returnControl->OnClick.SetDynamic(this, &BookingViewDataMenu::ReturnToBookingView);

	firstName = CreateLabel(Rect(10, 60, 250, 20), L"");
	lastName = CreateLabel(Rect(10, 90, 250, 20), L"");
	numberOfPeople = CreateLabel(Rect(10, 120, 250, 20), L"");
	calendar = CreateCalendar(Rect(10, 160, 250, 20));
	calendar->SetMaxSelected(15);

	ButtonControl* _deleteControl = CreateButton(Rect(10, 500, 100, 20), TEXT("Delete"));
	_deleteControl->OnClick.SetDynamic(this, &BookingViewDataMenu::Delete);

	isInitialized = true; 
	Close(); 
	
}

void BookingViewDataMenu::Open()
{
	const Booking* _current = BookingViewMenu::CurrentBooking;
	if (_current == nullptr)
	{
		ReturnToBookingView();
		return;
	}
	Client _client = _current->GetClient();
	firstName->SetText("First Name: " + _client.FirstName());
	lastName->SetText("last Name: " + _client.LastName());
	numberOfPeople->SetText("Number Of People" + std::to_string(_current->NumberOfPeople())); 
	calendar->SetValue(_current->ArrivedDate(), _current->DepartureDate());
	titleControl->SetText("Booking of: " + _client.FirstName() + " " + _client.LastName()); 
	super::Open();
}
#pragma endregion override