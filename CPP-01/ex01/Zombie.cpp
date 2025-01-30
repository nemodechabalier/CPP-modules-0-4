/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:18:27 by nde-chab          #+#    #+#             */
/*   Updated: 2024/11/06 20:11:18 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) {
	this->name = name;
	std::cout << "zombie : " << name << " created" << std::endl;
}
Zombie::Zombie(){
	std::cout << "zombie horde from created" << std::endl;
}

Zombie::~Zombie(void){
	std::cout << "zombie : " << name << " destroyed" << std::endl;
}

void Zombie::announce(void){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string& name){
	this->name = name;
}