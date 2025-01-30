#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>


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
	void addContact(const Contact& newContact);

	// Méthode pour afficher la liste des contacts
	void displayContacts() const;

	// Méthode pour afficher un contact spécifique
	void displayContact(int index) const;

	// chaine de charactere ok
	bool correct_input(std::string output, std::string* input);

	bool created_contact(Contact *newcontact);

	void displayEnd(bool eol);

	//add contact
	bool ADD(PhoneBook *phone);

	//search
	bool SEARCH(PhoneBook *phone);

};


#endif