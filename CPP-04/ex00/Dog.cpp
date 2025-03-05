#include "Dog.hpp"



/* ............................................ORTHODOX CANONICAL FORM ............................................*/

Dog::Dog(): Animal() {
	_type = "Dog";
	std::cout << "Dog: default constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog: default destructor called" << std::endl;
}

Dog::Dog(const Dog &other): Animal(other) {
	_type = "Dog";
	std::cout << "Dog: copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &other) {
	if (this != &other)
		_type = other._type;
	std::cout << "Dog: copy assignment operator called" << std::endl;
	return *this;
}


/* ............................................ FUNCTIONS .........................................................*/

void Dog::makeSound() const {
	std::cout << "type = " << _type << " \"Woof Woof\"" << std::endl;
}