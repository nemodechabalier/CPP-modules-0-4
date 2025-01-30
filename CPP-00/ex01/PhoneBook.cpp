
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : contactCount(0), oldestIndex(0) {}

void PhoneBook::addContact(const Contact& newContact) {
	if (contactCount < 8) {
		contacts[contactCount] = newContact;
		contactCount++;
	}
	else {
		contacts[oldestIndex] = newContact;
		oldestIndex = (oldestIndex + 1) % 8;
	}
	std::cout << "Contact ajouté avec succès !" << std::endl;
}

void PhoneBook::displayContacts() const {
	std::cout << "  Index|  First name|  Last Name|   Nickname" << std::endl;
	for (int i = 0; i < contactCount && i < 8; i++) {
		std::cout << "      " << i << "| ";
		for (int j = contacts[i].getFirstName().substr(0, 10).length(); j <= 10; j++)
			std::cout << " ";
		std::cout << contacts[i].getFirstName().substr(0, 10);
		std::cout << "|";
		for (int j = contacts[i].getLastName().substr(0, 10).length(); j <= 10; j++)
			std::cout << " ";
		std::cout << contacts[i].getLastName().substr(0, 10);
		std::cout << "|";
		for (int j = contacts[i].getNickname().substr(0, 10).length(); j <= 10; j++)
			std::cout << " ";
		std::cout << contacts[i].getNickname().substr(0, 10);
		std::cout << "" << std::endl;
	}
}

void PhoneBook::displayContact(int index) const {
	if (index < 0 || index >= contactCount || index >= 8)
	{
		std::cout << "Index invalide." << std::endl;
		return;
	}
	std::cout << "Prénom: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Nom: " << contacts[index].getLastName() << std::endl;
	std::cout << "Surnom: " << contacts[index].getNickname() << std::endl;
	std::cout << "Téléphone: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::displayEnd(bool eol) {
	if (eol)
		std::cout << "Ctrl+D detected" << std::endl;
	std::cout << "Au revoir !" << std::endl;
}

bool isPrintableString(const std::string& str) {
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isprint(str[i]))
			return (false);
	}
	return true;
}

bool PhoneBook::correct_input(std::string output, std::string* input) {
	while (1)
	{
		std::cout << output << std::endl;
		if (!std::getline(std::cin, *input))
			return false;
		if (input->length() > 0 && isPrintableString(*input))
			break;
		std::cout << "Error can't be empty or not printable" << std::endl;
	}
	return true;
}

bool PhoneBook::created_contact(Contact* contact) {

	std::string input;

	if (correct_input("Enter your first name : ", &input) == true)
		contact->setFirstName(input);
	else
		return (false);
	if (correct_input("Enter your last name : ", &input) == true)
		contact->setLastName(input);
	else
		return (false);
	if (correct_input("Enter your nickname : ", &input) == true)
		contact->setNickname(input);
	else
		return (false);
	if (correct_input("Enter your phone number : ", &input) == true)
		contact->setPhoneNumber(input);
	else
		return (false);
	if (correct_input("Enter your darkest secret : ", &input) == true)
		contact->setDarkestSecret(input);
	else
		return (false);
	return (true);
}

bool PhoneBook::ADD(PhoneBook* phone) {
	Contact new_contact;

	if (created_contact(&new_contact) == true) {
		phone->addContact(new_contact);
		return (true);
	}
	return (false);
}

bool PhoneBook::SEARCH(PhoneBook* phone) {
	phone->displayContacts();
	std::cout << "Enter the index of the contact to be displayed in detail : " << std::endl;
	int index;
	std::cin >> index;
	if (std::cin.eof())
		return (false);
	else if (std::cin.fail()) {
		std::cout << "Invalid index" << std::endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		return (true);
	}
	phone->displayContact(index);
	std::cin.ignore(10000, '\n');
	return (true);
}
