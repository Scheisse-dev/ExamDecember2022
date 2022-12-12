#include "MainMenu.h"
#include "../../../Utils/DataBase/MenuDataBase.h"
#include"../../Control/Label/LabelControl.h"
#include"../../Control/Button/ButtonControl.h"
#include"../../Window.h"

#pragma region constructor
MainMenu::MainMenu(Window* _owner) : super (_owner, MAINMENU) {}
#pragma endregion constructor

#pragma region override
void MainMenu::Initialize()
{
	super::Initialize();
	CreateButton(Rect(60, 50, 200, 20), TEXT("Create Booking")); 
	CreateButton(Rect(60, 80, 200, 20), TEXT("View Booking"));
	isInitialized = true;


}
#pragma endregion override