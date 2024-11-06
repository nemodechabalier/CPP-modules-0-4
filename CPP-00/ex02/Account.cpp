/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:35:46 by nde-chab          #+#    #+#             */
/*   Updated: 2024/11/02 16:46:02 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts),
										_amount(initial_deposit),
										_nbDeposits(0),
										_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}
~Account(void)
{
	_nbAcount--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
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

static int   Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

static int  Account::getTotalAmount(void)
{
	return _totalAmount;
}

static int  Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

static int  Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}


static void displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
			  << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
			  << ";deposits:" << getNbDeposits() << ";withdrawals:"
			  << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
              << ";deposit:" << deposit;

    // Mise à jour de l'état du compte
    _amount += deposit;
    _nbDeposits += 1;

    // Mise à jour des totaux globaux
    _totalAmount += deposit;
    _totalNbDeposits += 1;

    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}