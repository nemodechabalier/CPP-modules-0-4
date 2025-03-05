#include "Cat.hpp"



/* ............................................ORTHODOX CANONICAL FORM ............................................*/

Cat::Cat(): Animal() {
	_type = "cat";
	std::cout << "Cat: default constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat: default destructor called" << std::endl;
}

Cat::Cat(const Cat &other): Animal(other) {
	_type = "cat";
	std::cout << "Cat: copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
	if (this != &other)
		_type = other._type;
	std::cout << "cat: copy assignment operator called" << std::endl;
	return *this;
}


/* ............................................ FUNCTIONS .........................................................*/

void Cat::makeSound() const {
	std::cout << "type = " << _type << " \"Meow Meow\"" << std::endl;
}