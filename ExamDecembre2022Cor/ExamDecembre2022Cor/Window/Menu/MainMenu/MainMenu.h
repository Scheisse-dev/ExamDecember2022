#pragma once
#include "../BaseMenu.h"


class MainMenu : public BaseMenu
{
	DECLARE_CLASS_INFO(BaseMenu)
#pragma region constructor
public: 
	MainMenu() = default; 
	MainMenu(Window* _owner);
	MainMenu(const MainMenu& _copy) = default; 
#pragma endregion constructor
#pragma region methods
public:
	void OpenBookingMenu();
	void OpenBookingView(); 
#pragma endregion methods 
#pragma region override
public:
	void Initialize() override; 
#pragma endregion override
};

