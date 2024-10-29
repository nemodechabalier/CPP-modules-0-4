/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:51:48 by nde-chab          #+#    #+#             */
/*   Updated: 2024/10/28 15:51:54 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

// Fonction pour remplir un contact avec des informations fournies par l'utilisateur
Contact createContact() {
    Contact contact;
    std::string input;

    std::cout << "Entrez le prénom : ";
    std::getline(std::cin, input);
    contact.setFirstName(input);

    std::cout << "Entrez le nom : ";
    std::getline(std::cin, input);
    contact.setLastName(input);

    std::cout << "Entrez le surnom : ";
    std::getline(std::cin, input);
    contact.setNickname(input);

    std::cout << "Entrez le numéro de téléphone : ";
    std::getline(std::cin, input);
    contact.setPhoneNumber(input);

    std::cout << "Entrez le secret le plus sombre : ";
    std::getline(std::cin, input);
    contact.setDarkestSecret(input);

    return contact;
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Bienvenue dans votre répertoire téléphonique !" << std::endl;

    while (true) {
        std::cout << "\nEntrez une commande (ADD, SEARCH, EXIT) : ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            Contact newContact = createContact();
            phoneBook.addContact(newContact);
        } 
        else if (command == "SEARCH") {
            phoneBook.displayContacts();
            std::cout << "Entrez l'index du contact à afficher en détail : ";
            int index;
            std::cin >> index;

            if (std::cin.fail()) {
                std::cout << "Index non valide." << std::endl;
                std::cin.clear(); // Réinitialise le flux
                std::cin.ignore(10000, '\n'); // Ignore les caractères restants dans le flux
            } else {
                phoneBook.displayContact(index);
                std::cin.ignore(10000, '\n'); // Ignore le retour à la ligne restant dans le flux
            }
        } 
        else if (command == "EXIT") {
            std::cout << "Au revoir !" << std::endl;
            break;
        } 
        else {
            std::cout << "Commande non reconnue. Veuillez entrer ADD, SEARCH, ou EXIT." << std::endl;
        }
    }

    return 0;
}
