#include "WrongCat.hpp"



/* ............................................ORTHODOX CANONICAL FORM ............................................*/

WrongCat::WrongCat(): WrongAnimal() {
	_type = "WrongCat";
	std::cout << "WrongCat: default constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat: default destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other) {
	_type = "WrongCat";
	std::cout << "WrongCat: copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other) {
	if (this != &other)
		_type = other._type;
	std::cout << "WrongCat: copy assignment operator called" << std::endl;
	return *this;
}


/* ............................................ FUNCTIONS .........................................................*/

void WrongCat::makeSound() const {
	std::cout << "type = " << _type << " \"Meow Meow\"" << std::endl;
}