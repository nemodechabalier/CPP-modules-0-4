/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:35:46 by nde-chab          #+#    #+#             */
/*   Updated: 2024/10/30 18:09:33 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account(int initial_deposit) : 
_accountIndex(_nbAccounts),
_amount(initial_deposit),
_nbDeposits(0),
_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(nullptr);	   // Obtenir l'heure actuelle
	std::tm *localTime = std::localtime(&now); // Convertir en heure locale

	std::cout << "["
			  << (localTime->tm_year + 1900) // Année
			  << (localTime->tm_mon + 1)	 // Mois (ajouter 1 car tm_mon commence à 0)
			  << localTime->tm_mday << "_"	 // Jour
			  << localTime->tm_hour			 // Heure
			  << localTime->tm_min			 // Minute
			  << localTime->tm_sec			 // Seconde
			  << "] ";
}

// static int	getNbAccounts( void ){
//	return this->_nbAccounts;
// }