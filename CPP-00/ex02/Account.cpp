/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:35:46 by nde-chab          #+#    #+#             */
/*   Updated: 2024/11/08 15:51:05 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;

int Account::_totalNbWithdrawals = 0;

int Account::_totalNbDeposits = 0;

int Account::_totalAmount = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts),
										_amount(initial_deposit),
										_nbDeposits(0),
										_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}
Account::~Account(void)
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);		   // Obtenir l'heure actuelle
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

int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
			  << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
			  << ";deposits:" << _nbDeposits << ";withdrawals:"
			  << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
			  << ";deposit:" << deposit;

	_amount += deposit;
	_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits += 1;

	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}
// void Account::makeDeposit(int deposit)
//{
//	_displayTimestamp();
//	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
//	_amount += deposit;
//	_nbDeposits += 1;
//	_totalAmount += deposit;
//	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
// }

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
}