#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/

ScavTrap::ScavTrap() : ClapTrap() {
	_name = "default Scav";
	_hit_point = 100;
	_energy_point = 50;
	_attack_damage = 20;
	_guard_mode = false;
	std::cout << "Scav : default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const& name) : ClapTrap(name) {
	_hit_point = 100;
	_energy_point = 50;
	_attack_damage = 20;
	_guard_mode = false;
	std::cout << "Scav : custom constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	_guard_mode = other._guard_mode;
	std::cout << "Scav : copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		_guard_mode = other._guard_mode;
		_name = other._name;
		_attack_damage = other._attack_damage;
		_hit_point = other._hit_point;
		_energy_point = other._energy_point;
	}
	std::cout << "Scav : assigment called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "Scav : default destructor called" << std::endl;
}

/* ............................................ GETRER - SETTER ...................................................*/

bool ScavTrap::take_guardMode(){
	return _guard_mode;
}

void ScavTrap::set_guardMode(bool mode) {
	_guard_mode = mode;
}

/* ............................................ FUNCTIONS .........................................................*/


void ScavTrap::attack(const std::string& target) {
	if (this->_hit_point <= 0) {
		std::cout << "ScavTrap " << this->_name << " is dead" << std::endl;
		return;
	}
	if (_energy_point == 0) {
		std::cout << "ScavTrap " << this->_name << " have no energy" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->_name << " attack " << target << ", causing " << this->get_attack_damage() << " points of damage!" << std::endl;
	_energy_point -= 1;
}

void ScavTrap::takeDamage(unsigned int amout) {
	if (amout > INT_MAX) {
		std::cout << "Overflow !!" << std::endl;
		return;
	}
	if (this->_hit_point <= 0) {
		std::cout << "ScavTrap " << this->_name << " is dead" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->_name << " take " << amout << " damage" << std::endl;
	this->_hit_point -= amout;
	if (this->_hit_point <= 0)
		std::cout << "ScavTrap " << this->_name << " died" << std::endl;
	return;
}

void ScavTrap::beRepaired(unsigned int amout) {
	if (amout > INT_MAX) {
		std::cout << "Overflow !!" << std::endl;
		return;
	}
	if (this->_hit_point <= 0) {
		std::cout << "ScavTrap " << this->_name << " is dead" << std::endl;
		return;
	}
	if (_energy_point == 0) {
		std::cout << "ScavTrap " << this->_name << " have no energy" << std::endl;
		_energy_point += 1;
		return;
	}
	std::cout << "ScavTrap " << this->_name << " repaire " << amout << std::endl;
	this->_hit_point += amout;
	if (_hit_point > 100)
		_hit_point = 100;
	std::cout << "ScavTrap " << this->_name << " have now " << _hit_point << " hit_point" << std::endl;
	_energy_point -= 1;
}

void ScavTrap::guardGate() {
	if (this->_hit_point <= 0) {
		std::cout << "ScavTrap " << this->_name << " is dead" << std::endl;
		return;
	}
	if (!_guard_mode) {
		_guard_mode = true;
		std::cout << "ScavTrap :" << _name << " is now in guard mode" << std::endl;
	}
	else
		std::cout << "ScavTrap :" << _name << " is already in guard mode" << std::endl;
}