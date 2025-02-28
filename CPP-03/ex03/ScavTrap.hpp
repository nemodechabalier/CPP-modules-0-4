#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

protected :
	bool _guard_mode;

public:
	ScavTrap();
	ScavTrap(std::string const &name);
	ScavTrap(const ScavTrap &other);
	ScavTrap& operator=(const ScavTrap &other);
	virtual ~ScavTrap();

	bool take_guardMode();
	void set_guardMode(bool mode);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void guardGate();
};


#endif