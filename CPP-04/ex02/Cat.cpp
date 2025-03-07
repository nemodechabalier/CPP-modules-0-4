#include "Cat.hpp"



/* ............................................ORTHODOX CANONICAL FORM ............................................*/

Cat::Cat(): Animal() {
	_type = "cat";
	_Brain = new Brain();
	std::cout << "Cat: default constructor called" << std::endl;
}

Cat::~Cat() {
	delete _Brain;
	std::cout << "Cat: default destructor called" << std::endl;
}

Cat::Cat(const Cat &other): Animal(other) {
	_Brain = new Brain(*other._Brain);
	_type = other._type;
	std::cout << "Cat: copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
	if (this != &other)
	{
		_type = other._type;
		delete _Brain;
		_Brain = new Brain(*other._Brain);
	}
	std::cout << "cat: copy assignment operator called" << std::endl;
	return *this;
}


/* ............................................ FUNCTIONS .........................................................*/

void Cat::makeSound() const {
	std::cout << "type = " << _type << " \"Meow Meow\"" << std::endl;
}