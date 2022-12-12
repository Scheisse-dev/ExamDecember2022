#pragma once
#include "../BaseMenu.h"

class BookingMenu : public BaseMenu
{
	DECLARE_CLASS_INFO(BaseMenu)
#pragma region constructor
public: 
	BookingMenu() = default; 
	BookingMenu(Window* _owner);
	BookingMenu(const BookingMenu& _copy) = default; 
#pragma endregion constructor
#pragma region override
public:
	void Initialize() override; 
#pragma endregion override
};

