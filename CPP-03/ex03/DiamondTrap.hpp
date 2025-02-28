#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

private:

	std::string _name;

public:

	using FragTrap::_hit_point; //100 hp ok
	using FragTrap::_attack_damage; //30 ok
	using ScavTrap::_energy_point; //50 ep ok
	using ScavTrap::attack;

	DiamondTrap();
	DiamondTrap(std::string const& name);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap& operator=(const DiamondTrap& other);
	~DiamondTrap();

	bool take_guardMode();
	void set_guardMode(bool mode);

	//void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void whoAmI();
};


#endif