/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:51:48 by nde-chab          #+#    #+#             */
/*   Updated: 2024/10/30 16:03:42 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

// Fonction pour remplir un contact avec des informations fournies par l'utilisateur

std::string correct_input(std::string output)
{
    std::string input;
    while (input.length() < 1)
    {
        std::cout << output << std::endl;
        if (!std::getline(std::cin, input))
            return ""; // Retourne une chaîne vide en cas d'échec
    }
    return input; // Retourne l'input valide
}

Contact createContact()
{
    Contact contact;
    std::string input;

    input = correct_input("Entrez le prénom : ");
    if (input.empty())
        return contact; // Ne continue pas si l'entrée est vide
    contact.setFirstName(input);

    input = correct_input("Entrez le nom : ");
    if (input.empty())
        return contact; // Vérifie l'entrée avant de l'utiliser
    contact.setLastName(input);

    input = correct_input("Entrez le surnom : ");
    if (input.empty())
        return contact; // Vérifie l'entrée avant de l'utiliser
    contact.setNickname(input);

    input = correct_input("Entrez le numéro de téléphone : ");
    if (input.empty())
        return contact; // Vérifie l'entrée avant de l'utiliser
    contact.setPhoneNumber(input);

    input = correct_input("Entrez le secret le plus sombre : ");
    if (input.empty())
        return contact; // Vérifie l'entrée avant de l'utiliser
    contact.setDarkestSecret(input);

    return contact; // Retourne le contact complet si tout a réussi
}

int verif_contact(Contact contact)
{
    if (contact.getDarkestSecret().length() == 0 || contact.getFirstName().length() == 0 || contact.getLastName().length() == 0 || contact.getNickname().length() == 0 || contact.getPhoneNumber().length() == 0)
        return (0);
    return (1);
}
int main()
{
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Bienvenue dans votre répertoire téléphonique !" << std::endl;

    while (true)
    {
        std::cout << "\nEntrez une commande (ADD, SEARCH, EXIT) : ";
        if (!std::getline(std::cin, command))
            break;

        if (command == "ADD")
        {
            Contact newContact = createContact();
            if (verif_contact(newContact) == 0)
                break;
            phoneBook.addContact(newContact);
        }
        else if (command == "SEARCH")
        {
            phoneBook.displayContacts();
            std::cout << "Entrez l'index du contact à afficher en détail : ";
            int index;
            std::cin >> index;
			
			if (std::cin.eof())
				break;
            else if (std::cin.fail())
            {
                std::cout << "Index non valide." << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
            else
            {
                phoneBook.displayContact(index);
                std::cin.ignore(10000, '\n');
            }
        }
        else if (command == "EXIT")
        {
            break;
        }
        else
        {
            std::cout << "Commande non reconnue. Veuillez entrer ADD, SEARCH, ou EXIT." << std::endl;
        }
    }
    std::cout << "\nAu revoir !" << std::endl;
    return 0;
}