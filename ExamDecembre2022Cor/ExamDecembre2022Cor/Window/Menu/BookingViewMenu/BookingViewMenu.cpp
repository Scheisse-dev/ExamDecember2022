#include "BookingViewMenu.h"
#include "../../../Utils/DataBase/MenuDataBase.h"
#include "../../../Booking/Manager/BookingManager.h"
#include "../../../Utils/Rect/Rect.h"
#include "../../../Booking/Booking.h"
#include "../../Control/Label/LabelControl.h"
#include "../../Control/Button/ButtonControl.h"

#pragma region f/p
Booking* BookingViewMenu::CurrentBooking = nullptr; 
#pragma endregion f/p
#pragma region constructor
BookingViewMenu::BookingViewMenu(Window* _owner) : super(_owner, BOOKINGVIEWMENU)
{}
#pragma endregion constructor
#pragma region methods
void BookingViewMenu::SetCurrentBooking(Booking* _booking)
{
	CurrentBooking = _booking;
}

void BookingViewMenu::DisplayBookings(const std::vector<Booking*>& _bookings)
{
	int _positionX = 10, _positionY = 30;
	int _index = 0; 
	for (Booking* _booking : _bookings)
	{
		Client _client = _booking->GetClient(); 
		const std::string _clientFullName = _client.FirstName() + " " + _client.LastName(); 
		const std::wstring _fullNameWstr = std::wstring(_clientFullName.begin(), _clientFullName.end());
		ButtonControl* _button = CreateButton(Rect(_positionX, _positionY, 250, 20), _fullNameWstr.c_str());
		_positionX += 260;
		_index++;
		if (_index % MAXCOLUMNNUMBER == 0)
		{
			_positionX = 10;
			_positionY += 30;
		}
	}
}

#pragma endregion methods
#pragma region override
void BookingViewMenu::Initialize()
{
	super::Initialize();
	textControl = CreateLabel(Rect(10, 20, 250, 20), L"");
	isInitialized = true;
	Close();
}

void BookingViewMenu::Open()
{
	std::vector<Booking*> _bookings = BookingManager::Instance()->Bookings();
	if (_bookings.empty())
	{
		textControl->SetText(L"No Bookings...");
	}
	else
	{
		DisplayBookings(_bookings);
		textControl->SetText(L"");
	}
	super::Open();
}

void BookingViewMenu::Close()
{
	const size_t _size = controls.size(); 
	for (size_t i = 0; i < _size; i++)
	{
		controls[1]->Hide(); 
		delete controls[1];
		controls.erase(controls.begin() + 1);

	}
}
#pragma endregion override