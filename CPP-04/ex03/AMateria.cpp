#include "AMateria.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/



AMateria::AMateria() {
	_type = "default";
	std::cout << "AMateria: default constructor called" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria: default destructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other) {
	_type = other._type;
	std::cout << "AMateria: copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &other) {
	if (this != &other)
	{
		_type = other._type;
	}
	std::cout << "AMateria: copy assignment operator called" << std::endl;
	return *this;
}

AMateria::AMateria(const std::string &type) {
	_type = type;
	std::cout << "AMateria: custom constructor called" << std::endl;
}

/* ............................................ GETRER - SETTER ...................................................*/

std::string const& AMateria::getType() const {
	return _type;
}

/* ............................................ FUNCTIONS .........................................................*/

