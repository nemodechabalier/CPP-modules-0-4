/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:57:52 by nde-chab          #+#    #+#             */
/*   Updated: 2024/11/07 16:18:23 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl created" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl destroyed" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.I really do !\n" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level)
{
	int number = -1;
	void (Harl:: * pointer[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string function[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	for (int i = 0; i < 4; i++)
	{
		if (level == function[i])
			number = i;
	}
	switch (number)
	{
	case 0:
		(this->*pointer[0])();
	case 1:
		(this->*pointer[1])();
	case 2:
		(this->*pointer[2])();
	case 3:
		(this->*pointer[3])();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}