#include "Booking.h"

#pragma region constructor
Booking::Booking(const DateTime& _arrivedDate, const DateTime& _departureDate, const Client& _client, int _numberOfPeople)
{
	arrivedDate = _arrivedDate;
	departureDate = _departureDate;
	client = _client; 
	numberOfPeople = _numberOfPeople;
}

Booking::Booking(const Booking& _copy)
{
	arrivedDate = _copy.arrivedDate;
	departureDate = _copy.departureDate;
	client = _copy.client;
	numberOfPeople = _copy.numberOfPeople;
}
#pragma endregion constructor
#pragma region methods
DateTime Booking::ArrivedDate() const
{
	return arrivedDate;
}

DateTime Booking::DepartureDate() const
{
	return departureDate;
}

Client Booking::GetClient() const
{
	return client;
}

int Booking::NumberOfPeople() const
{
	return numberOfPeople;
}
#pragma endregion methods