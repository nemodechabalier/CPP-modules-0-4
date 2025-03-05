#include "WrongAnimal.hpp"


/* ............................................ORTHODOX CANONICAL FORM ............................................*/

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "WrongAnimal: default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal: default destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
	std::cout << "WrongAnimal: copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other)
		_type = other._type;
	std::cout << "WrongAnimal: copy assignment operator called" << std::endl;
	return *this;
}

/* ............................................ GETRER - SETTER ...................................................*/

std::string WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::setType(const std::string& new_type) {
	_type = new_type;
}

/* ............................................ FUNCTIONS .........................................................*/

void WrongAnimal::makeSound() const {
	std::cout << "type = " << _type << " \"Sound Undifined\"" << std::endl;
}