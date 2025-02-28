#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap() {
	_name = "default Diamond";
	ClapTrap::_name = _name + "_clap_name";
	FragTrap::set_attack_damage(30);
	_hit_point = FragTrap::_hit_point;
	_energy_point = ScavTrap::_energy_point;
	_attack_damage = FragTrap::_attack_damage;
	std::cout << "Diamond : default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const& name) : ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name") {
	FragTrap::set_attack_damage(30);
	ScavTrap::set_energy_point(50);
	FragTrap::set_hit_point(100);
	_name = name;
	_hit_point = FragTrap::_hit_point;
	_energy_point = ClapTrap::_energy_point;
	_attack_damage = FragTrap::_attack_damage;
	std::cout << "Diamond : custom constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other) {
	this->_name = other._name;
	this->_hit_point = other._hit_point;
	this->_energy_point = other._energy_point;
	this->_attack_damage = other._attack_damage;
	this->_guard_mode = other._guard_mode;
	std::cout << "Diamond : copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		_name = other._name;
	}
	std::cout << "Diamond : assigment called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Diamond : default destructor called" << std::endl;
}

/* ............................................ FUNCTIONS .........................................................*/


//void DiamondTrap::attack(const std::string& target) {
//	ScavTrap::attack(target);
//}

void DiamondTrap::takeDamage(unsigned int amout) {
	if (amout > INT_MAX) {
		std::cout << "Overflow !!" << std::endl;
		return;
	}
	if (this->_hit_point <= 0) {
		std::cout << "DiamondTrap " << this->_name << " is dead" << std::endl;
		return;
	}
	std::cout << "DiamondTrap " << this->_name << " take " << amout << " damage" << std::endl;
	this->_hit_point -= amout;
	if (this->_hit_point <= 0)
		std::cout << "DiamondTrap " << this->_name << " died" << std::endl;
	return;
}

void DiamondTrap::beRepaired(unsigned int amout) {
	if (amout > INT_MAX) {
		std::cout << "Overflow !!" << std::endl;
		return;
	}
	if (this->_hit_point <= 0) {
		std::cout << "DiamondTrap " << this->_name << " is dead" << std::endl;
		return;
	}
	if (_energy_point == 0) {
		std::cout << "DiamondTrap " << this->_name << " have no energy" << std::endl;
		_energy_point += 1;
		return;
	}
	std::cout << "DiamondTrap " << this->_name << " repaire " << amout << std::endl;
	this->_hit_point += amout;
	if (_hit_point > 100)
		_hit_point = 100;
	std::cout << "DiamondTrap " << this->_name << " have now " << _hit_point << " hit_point" << std::endl;
	_energy_point -= 1;
}

void DiamondTrap::whoAmI(void) {
	if (this->_hit_point <= 0) {
		std::cout << "DiamondTrap " << this->_name << " is dead" << std::endl;
		return;
	}
	std::cout << "DiamondTrap named " << this->_name
		<< " and my ClapTrap is " << ClapTrap::_name << std::endl;
}
