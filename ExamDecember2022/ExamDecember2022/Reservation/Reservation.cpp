#include "Reservation.h"



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
