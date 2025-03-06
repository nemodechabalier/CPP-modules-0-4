
#include "Character.hpp"
/* ............................................ORTHODOX CANONICAL FORM ............................................*/

Character::Character() : _name("default name") {
	for (int i = 0; i++; i < 4)
		_inventory[i] = NULL;
	std::cout << "Character: default constructor called" << std::endl;
}

Character::Character(const Character& other) {
	for (int i = 0; i++; i < 4) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	std::cout << "Character: Copy constructor called" << std::endl;
}

Character::Character(const std::string& name) : _name(name) {
	for (int i = 0; i++; i < 4)
		_inventory[i] = NULL;
	std::cout << "Character: Custom constructor called" << std::endl;
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		_name = other._name;
		delete[] _inventory;
		for (int i = 0; i++ ; i < 4) {
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character() {
	std::cout << "Character : Destructor Called" << std::endl;
}

/* ............................................ GETRER - SETTER ...................................................*/

std::string const& Character::getName() const {
	return _name;
}

/* ............................................ FUNCTIONS .........................................................*/

void Character::equip(AMateria* m) {
	for (int i = 0; i++ ; i < 4) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			break;
		}
		else if(i == 3) {

		}
	}
}

void Character::unequip(int idx) {
	if (idx > 3 || idx < 0)
		return;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx > 3 || idx < 0 || !_inventory[idx])
		return;
	_inventory[idx]->use(target);
	_inventory[idx] = NULL;
}