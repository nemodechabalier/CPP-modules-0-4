/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:12:05 by nde-chab          #+#    #+#             */
/*   Updated: 2024/11/06 20:20:30 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string &type)
{
	std::cout << "Weapon created" << std::endl;
	this->type = type;
}

Weapon::Weapon()
{
	std::cout << "Weapon created" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon destroyed" << std::endl;
}

std::string Weapon::getType(void) const
{
	return (this->type);
}

void Weapon::setType(const std::string &type)
{
	this->type = type;
}