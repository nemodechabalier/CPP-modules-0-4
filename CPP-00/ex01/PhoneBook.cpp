/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:53:02 by nde-chab          #+#    #+#             */
/*   Updated: 2024/10/28 15:53:25 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : contactCount(0), oldestIndex(0) {}

void PhoneBook::addContact(const Contact &newContact)
{
	if (contactCount < 8)
	{
		contacts[contactCount] = newContact;
		contactCount++;
	}
	else
	{

		contacts[oldestIndex] = newContact;
		oldestIndex = (oldestIndex + 1) % 8;
	}
	std::cout << "Contact ajouté avec succès !" << std::endl;
}

void PhoneBook::displayContacts() const
{
	std::cout << "Index | Prénom      | Nom         | Surnom" << std::endl;
	for (int i = 0; i < contactCount && i < 8; i++)
	{
		std::cout << "   " << i << "   | ";
		std::cout << contacts[i].getFirstName().substr(0, 10) << " | ";
		std::cout << contacts[i].getLastName().substr(0, 10) << " | ";
		std::cout << contacts[i].getNickname().substr(0, 10) << std::endl;
	}
}

void PhoneBook::displayContact(int index) const {
    if (index < 0 || index >= contactCount || index >= 8) {
        std::cout << "Index invalide." << std::endl;
        return;
    }
    std::cout << "Prénom: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Nom: " << contacts[index].getLastName() << std::endl;
    std::cout << "Surnom: " << contacts[index].getNickname() << std::endl;
    std::cout << "Téléphone: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Secret: " << contacts[index].getDarkestSecret() << std::endl;
}
