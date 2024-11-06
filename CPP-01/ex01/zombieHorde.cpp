/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:56:55 by nde-chab          #+#    #+#             */
/*   Updated: 2024/11/06 19:40:48 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << "error N can't be negative" << std::endl;
		return NULL;
	}
	Zombie *horde = new Zombie[N];
	if (!horde)
		return(NULL);
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);
	}
	return (horde);
}