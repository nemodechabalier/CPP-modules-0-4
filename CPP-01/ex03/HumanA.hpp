#ifndef HUMANA_HPP
#define HUMANA_HPP

class HumanA {
	
private:
	std::string name;
	Weapon weapon;

public:
	HumanA(std::string &name, Weapon &weapon);

	void setWeapon(const std::string &type);

}

#include "Weapon.hpp"

#endif