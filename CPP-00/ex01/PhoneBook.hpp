#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	// constructeur
	Contact();

	// Méthodes pour définir les informations du contact
	void setFirstName(const std::string &firstName);
	void setLastName(const std::string &lastName);
	void setNickname(const std::string &nickname);
	void setPhoneNumber(const std::string &phoneNumber);
	void setDarkestSecret(const std::string &darkestSecret);

	// Méthodes pour obtenir les informations du contact
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
};

class PhoneBook
{
private:
	Contact contacts[8];
	int contactCount;
	int oldestIndex;

public:
	// constructeur
	PhoneBook();

	// Méthodes pour ajouter un contact
	void addContact(const Contact &newContact);

	// Méthode pour afficher la liste des contacts
	void displayContacts() const;

	// Méthode pour afficher un contact spécifique
	void displayContact(int index) const;
};


#endif