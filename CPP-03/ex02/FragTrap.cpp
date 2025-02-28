#include "FragTrap.hpp"
#include "ClapTrap.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/

FragTrap::FragTrap() : ClapTrap() {
	_name = "default Scav";
	_hit_point = 100;
	_energy_point = 100;
	_attack_damage = 30;
	std::cout << "Frag : default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const& name) : ClapTrap(name) {
	_hit_point = 100;
	_energy_point = 100;
	_attack_damage = 30;
	std::cout << "Frag : custom constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "Frag : copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		_name = other._name;
		_attack_damage = other._attack_damage;
		_hit_point = other._hit_point;
		_energy_point = other._energy_point;
	}
	std::cout << "Frag : assigment called" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "Frag : default destructor called" << std::endl;
}

/* ............................................ FUNCTIONS .........................................................*/


void FragTrap::attack(const std::string& target) {
	if (this->_hit_point <= 0) {
		std::cout << "FragTrap " << this->_name << " is dead" << std::endl;
		return;
	}
	if (_energy_point == 0) {
		std::cout << "FragTrap " << this->_name << " have no energy" << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->_name << " attack " << target << ", causing " << this->get_attack_damage() << " points of damage!" << std::endl;
	_energy_point -= 1;
}

void FragTrap::takeDamage(unsigned int amout) {
	if (amout > INT_MAX) {
		std::cout << "Overflow !!" << std::endl;
		return;
	}
	if (this->_hit_point <= 0) {
		std::cout << "FragTrap " << this->_name << " is dead" << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->_name << " take " << amout << " damage" << std::endl;
	this->_hit_point -= amout;
	if (this->_hit_point <= 0)
		std::cout << "FragTrap " << this->_name << " died" << std::endl;
	return;
}

void FragTrap::beRepaired(unsigned int amout) {
	if (amout > INT_MAX) {
		std::cout << "Overflow !!" << std::endl;
		return;
	}
	if (this->_hit_point <= 0) {
		std::cout << "FragTrap " << this->_name << " is dead" << std::endl;
		return;
	}
	if (_energy_point == 0) {
		std::cout << "FragTrap " << this->_name << " have no energy" << std::endl;
		_energy_point += 1;
		return;
	}
	std::cout << "FragTrap " << this->_name << " repaire " << amout << std::endl;
	this->_hit_point += amout;
	if (_hit_point > 100)
		_hit_point = 100;
	std::cout << "FragTrap " << this->_name << " have now " << _hit_point << " hit_point" << std::endl;
	_energy_point -= 1;
}

void FragTrap::highFivesGuys(void) {
	if (this->_hit_point <= 0) {
		std::cout << "FragTrap " << this->_name << " is dead" << std::endl;
		return;
	}
    std::cout << "FragTrap " << this->_name << " requests a positive high five! Anyone?" << std::endl;
}