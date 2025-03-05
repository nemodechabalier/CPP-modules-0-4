#include "Animal.hpp"


/* ............................................ORTHODOX CANONICAL FORM ............................................*/

Animal::Animal(): _type("Animal") {
	std::cout << "Animal: default constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal: default destructor called" << std::endl;
}

Animal::Animal(const Animal &other): _type(other._type) {
	std::cout << "Animal: copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &other) {
	if (this != &other)
		_type = other._type;
	std::cout << "Animal: copy assignment operator called" << std::endl;
	return *this;
}

/* ............................................ GETRER - SETTER ...................................................*/

std::string Animal::getType() const {
	return _type;
}

void Animal::setType(const std::string &new_type) {
	_type = new_type; 
}

/* ............................................ FUNCTIONS .........................................................*/

void Animal::makeSound() const {
	std::cout << "type = " << _type << " \"Sound Undifined\"" << std::endl;
}