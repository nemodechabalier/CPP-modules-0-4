#include "Contact.hpp"
#include "PhoneBook.hpp"

// Constructeur
Contact::Contact(void) {}

// Méthodes set
void Contact::setFirstName(const std::string &firstName)
{
	this->firstName = firstName;
}
void Contact::setLastName(const std::string &Lastname)
{
	this->lastName = Lastname;
}
void Contact::setNickname(const std::string &nickname)
{
	this->nickname = nickname;
}
void Contact::setPhoneNumber(const std::string &phoneNumber)
{
	this->phoneNumber = phoneNumber;
}
void Contact::setDarkestSecret(const std::string &darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

// Méthodes get
std::string Contact::getFirstName() const
{
	return firstName;
}

std::string Contact::getLastName() const
{
	return lastName;
}

std::string Contact::getNickname() const
{
	return nickname;
}

std::string Contact::getPhoneNumber() const
{
	return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}