#include "ClapTrap.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/

ClapTrap::ClapTrap(const std::string& name) :_name(name), _hit_point(10), _energy_point(10), _attack_damage(0) {
	std::cout << "Clap : default constructor called" << std::endl;
}

ClapTrap::ClapTrap() : _hit_point(10), _energy_point(10), _attack_damage(0) {
	_name = "default Clap";
	std::cout << "Clap : custom constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Clap : default destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other) {
		_attack_damage = other._attack_damage;
		_energy_point = other._energy_point;
		_hit_point = other._hit_point;
		_name = other._name;
	}
	std::cout << "Clap : assigment called" << std::endl;
	return *this;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	_attack_damage = other._attack_damage;
	_energy_point = other._energy_point;
	_hit_point = other._hit_point;
	_name = other._name;
	std::cout << "Clap : copy constructor called" << std::endl;
}

/* ............................................ GETRER - SETTER ...................................................*/

std::string ClapTrap::get_name() {
	return this->_name;
}

int ClapTrap::get_hit_point() {
	return this->_hit_point;
}

int ClapTrap::get_attack_damage() {
	return this->_attack_damage;
}

int ClapTrap::get_energy_point() {
	return this->_energy_point;
}

void ClapTrap::set_name(const std::string& name) {
	this->_name = name;
}

void ClapTrap::set_hit_point(int nb) {
	this->_hit_point = nb;
}
void ClapTrap::set_energy_point(int nb) {
	this->_energy_point = nb;
}

void ClapTrap::set_attack_damage(int nb) {
	this->_attack_damage = nb;
}


/* ............................................ FUNCTIONS .........................................................*/

void ClapTrap::attack(const std::string& target) {
	if (this->_hit_point <= 0) {
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
		return;
	}
	if (_energy_point == 0) {
		std::cout << "ClapTrap " << this->_name << " have no energy" << std::endl;
		_energy_point += 1;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " attack " << target << ", causing " << this->get_attack_damage() << " points of damage!" << std::endl;
	_energy_point -= 1;
}

void ClapTrap::takeDamage(unsigned int amout) {
	if (amout > INT_MAX) {
		std::cout << "Overflow !!" << std::endl;
		return;
	}
	if (this->_hit_point <= 0) {
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " take " << amout << " damage" << std::endl;
	this->_hit_point -= amout;
	if (this->_hit_point <= 0)
		std::cout << "ClapTrap " << this->_name << " died" << std::endl;
	return;
}

void ClapTrap::beRepaired(unsigned int amout) {
	if (amout > INT_MAX) {
		std::cout << "Overflow !!" << std::endl;
		return;
	}
	if (this->_hit_point <= 0) {
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
		return;
	}
	if (_energy_point == 0) {
		std::cout << "ClapTrap " << this->_name << " have no energy" << std::endl;
		_energy_point += 1;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " repaire " << amout << std::endl;
	this->_hit_point += amout;
	if (_hit_point > 10)
		_hit_point = 10;
	std::cout << "ClapTrap " << this->_name << " have now " << _hit_point << " hit_point" << std::endl;
	_energy_point -= 1;
}

