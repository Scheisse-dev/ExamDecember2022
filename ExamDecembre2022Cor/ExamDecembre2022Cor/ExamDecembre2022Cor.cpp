#include <iostream>
#include "Window/Window.h"
#include "Window/Menu/MainMenu/MainMenu.h"
#include "Window/Menu/BookingMenu/BookingMenu.h"
#include "Utils/DataBase/MenuDataBase.h"

int main()
{
	Window win = Window(L"Hotel O3D", 900, 800); 
	//win.RegisterMenu(new MainMenu(&win)); 
	win.RegisterMenu(new BookingMenu(&win));
	win.SetCurrentMenu(BOOKINGMENU);
	win.Open(); 
}

