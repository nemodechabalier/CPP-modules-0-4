
#include "Character.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/

Character::Character() : _name("default name"), _useCount(0) {
	for (int i = 0; i < 4;i++)
		_inventory[i] = NULL;
	_used = NULL;
	//std::cout << "Character: default constructor called" << std::endl;
}

Character::Character(const Character& other) {
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	_name = other._name;
	_useCount = other._useCount;
	if (_useCount > 0) {
		_used = new AMateria * [_useCount];
		for (int i = 0; i < _useCount; i++) {
			_used[i] = other._used[i]->clone();
		}
	}
	else
		_used = NULL;
	//std::cout << "Character: Copy constructor called" << std::endl;
}

Character::Character(const std::string& name) : _name(name), _useCount(0) {
	for (int i = 0; i < 4;i++)
		_inventory[i] = NULL;
	_used = NULL;
	//std::cout << "Character: Custom constructor called" << std::endl;
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		for (int i = 0; i < 4;i++) {
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
		_name = other._name;
		_useCount = other._useCount;
		if (_useCount > 0) {
			_used = new AMateria * [_useCount];
			for (int i = 0; i < _useCount; i++) {
				_used[i] = other._used[i]->clone();
			}
		}
		else
			_used = NULL;
	}
	return *this;
}

Character::~Character() {
	for (int j = 0; j < _useCount; j++) {
		for (int i = 0; i < 4; i++) {
			if (_inventory[i] == _used[j])
			_inventory[i] = NULL;
		}
	}
	for (int i = 0; i < _useCount; i++) {
		delete _used[i];
	}
	delete[] _used;
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
		delete _inventory[i];
	}
	//std::cout << "Character : Destructor Called" << std::endl;
}

/* ............................................ GETRER - SETTER ...................................................*/

std::string const& Character::getName() const {
	return _name;
}

/* ............................................ FUNCTIONS .........................................................*/

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << "Error: Trying to equip a null Materia!" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			std::cout << "Materia equipped in slot " << i << std::endl;
			return;
		}
	}

	std::cout << "Inventory full! Moving Materia to used storage." << std::endl;
	Add_used(m);
}


void Character::unequip(int idx) {
	if (idx > 3 || idx < 0 || !_inventory[idx])
		return;
	Add_used(_inventory[idx]);
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx > 3 || idx < 0 || !_inventory[idx]) {
		return;
	}
	_inventory[idx]->use(target);
	Add_used(_inventory[idx]);
	_inventory[idx] = NULL;
}

void Character::Add_used(AMateria* Materia) {
	if (Materia == NULL)
		return;
	AMateria** new_used = new AMateria * [_useCount + 1];
	for (int i = 0; i < _useCount; i++) {
		new_used[i] = _used[i];
	}
	new_used[_useCount] = Materia;
	_useCount++;
	delete[] _used;
	_used = new_used;
}