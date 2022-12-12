#include "Client.h"


#pragma region construct
Client::Client(const std::string& _firstName, const std::string& _lastName)
{
	firstName = _firstName;
	lastName = _lastName;

}

Client::Client(const Client& _copy)
{
	firstName = _copy.firstName;
	lastName = _copy.lastName;
}
#pragma endregion construct
#pragma region methods
std::string Client::FirstName()
{
	return firstName;
}

std::string Client::LastName()
{
	return lastName;
}
#pragma endregion methods