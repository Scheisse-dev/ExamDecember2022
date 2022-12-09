#include "Reservation.h"
#include <iostream>
#include <Windows.h>


Reservation::Reservation(std::string _firstName, std::string _lastName, int _people, std::string _date)
{
	firstName = _firstName; 
	lastName = _lastName;
	people = _people; 
	date = _date; 

}

Reservation::Reservation(const Reservation& _copy)
{
	firstName = _copy.firstName;
	lastName = _copy.lastName;
	people = _copy.people;
	date = _copy.date;

}

void Reservation::ReservationRegister()
{
	std::cout << "alors j'avais l'idee de stocker dans un vecteur les hwnd de fenetre creer, mais j'ai pas reussi donc bon bah...";
	ShellExecute(0, 0, L"https://www.youtube.com/watch?v=dQw4w9WgXcQ", 0, 0, SW_SHOW);
}
