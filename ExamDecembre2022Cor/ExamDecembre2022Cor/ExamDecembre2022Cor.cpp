#include <iostream>
#include "Window/Window.h"
#include "Window/Menu/MainMenu/MainMenu.h"
#include "Window/Menu/BookingMenu/BookingMenu.h"
#include "Window/Menu/BookingViewMenu/BookingViewMenu.h"
#include "Window/Menu/BookingViewDataMenu/BookingViewDataMenu.h"
#include "Utils/DataBase/MenuDataBase.h"
#include "Utils/DateTime/DateTime.h"

int main()
{
	Window win = Window(L"Hotel O3D", 900, 800); 
	win.RegisterMenu(new MainMenu(&win)); 
	win.RegisterMenu(new BookingMenu(&win));
	win.RegisterMenu(new BookingViewMenu(&win));
	win.RegisterMenu(new BookingViewDataMenu(&win));
	win.SetCurrentMenu(MAINMENU);
	
	win.Open(); 
}

