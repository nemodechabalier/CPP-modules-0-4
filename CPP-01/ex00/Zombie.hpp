/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:57:19 by nde-chab          #+#    #+#             */
/*   Updated: 2024/11/06 17:57:20 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>




class Zombie
{
private:
	std::string name;

public:
	Zombie(const std::string &name);
	~Zombie();

	void announce(void);
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif