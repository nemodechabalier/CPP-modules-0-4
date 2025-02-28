#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap {

public:
	FragTrap();
	FragTrap(std::string const &name);
	FragTrap(const FragTrap &other);
	FragTrap& operator=(const FragTrap &other);
	virtual ~FragTrap();

	bool take_guardMode();
	void set_guardMode(bool mode);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void highFivesGuys();
};


#endif