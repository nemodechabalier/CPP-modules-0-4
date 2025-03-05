#include "WrongDog.hpp"



/* ............................................ORTHODOX CANONICAL FORM ............................................*/

WrongDog::WrongDog(): WrongAnimal() {
	_type = "WrongDog";
	std::cout << "WrongDog: default constructor called" << std::endl;
}

WrongDog::~WrongDog() {
	std::cout << "WrongDog: default destructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog &other): WrongAnimal(other) {
	_type = "WrongDog";
	std::cout << "WrongDog: copy constructor called" << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog &other) {
	if (this != &other)
		_type = other._type;
	std::cout << "WrongDog: copy assignment operator called" << std::endl;
	return *this;
}


/* ............................................ FUNCTIONS .........................................................*/

void WrongDog::makeSound() const {
	std::cout << "type = " << _type << " \"Woof Woof\"" << std::endl;
}