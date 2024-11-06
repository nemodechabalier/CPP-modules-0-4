/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:35:11 by nde-chab          #+#    #+#             */
/*   Updated: 2024/11/06 19:58:24 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	// 1. Déclaration et initialisation de la chaîne de caractères
	std::string brain = "HI THIS IS BRAIN";

	// 2. Création d'un pointeur vers la chaîne
	std::string *stringPTR = &brain;

	// 3. Création d'une référence vers la chaîne
	std::string &stringREF = brain;

	// 4. Affichage des adresses
	std::cout << "Adresse de la chaîne: " << &brain << std::endl;
	std::cout << "Adresse stockée dans stringPTR: " << stringPTR << std::endl;
	std::cout << "Adresse stockée dans stringREF: " << &stringREF << std::endl;

	std::cout << std::endl; // Ligne vide pour séparer les sections

	// 5. Affichage des valeurs
	std::cout << "Valeur de la chaîne: " << brain << std::endl;
	std::cout << "Valeur pointée par stringPTR: " << *stringPTR << std::endl;
	std::cout << "Valeur pointée par stringREF: " << stringREF << std::endl;

	return 0;
}
