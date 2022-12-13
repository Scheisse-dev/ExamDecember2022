#include "MainMenu.h"
#include "../../../Utils/DataBase/MenuDataBase.h"
#include"../../Control/Label/LabelControl.h"
#include"../../Control/Button/ButtonControl.h"
#include"../../Window.h"

#pragma region constructor
MainMenu::MainMenu(Window* _owner) : super (_owner, MAINMENU) {}
#pragma endregion constructor
#pragma region methods
void MainMenu::OpenBookingMenu()
{
	owner->SetCurrentMenu(BOOKINGMENU); 
}
void MainMenu::OpenBookingView()
{
	owner->SetCurrentMenu(BOOKINGVIEWMENU);
}
#pragma endregion methods
#pragma region override

void MainMenu::Initialize()
{
	super::Initialize();
	
	ButtonControl* _createControl = CreateButton(Rect(60, 50, 200, 20), TEXT("Create Booking")); 
	_createControl->OnClick.SetDynamic(this, &MainMenu::OpenBookingMenu); 
	ButtonControl*  _viewControl = CreateButton(Rect(60, 80, 200, 20), TEXT("View Booking"));
	_viewControl->OnClick.SetDynamic(this, &MainMenu::OpenBookingView); 
	isInitialized = true;
	Close();


}
#pragma endregion override